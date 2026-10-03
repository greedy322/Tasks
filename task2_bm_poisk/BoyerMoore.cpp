#include "BoyerMoore.h"

std::vector<int> BuildShiftTable(const std::string& pattern) {
    const int kAlphabetSize = 256;
    const int m = static_cast<int>(pattern.size());

    std::vector<int> table(kAlphabetSize, m);

    for (int i = 0; i < m - 1; ++i) {
        const auto c = static_cast<unsigned char>(pattern[i]);
        table[c] = m - 1 - i;
    }

    return table;
}

int FindFirst(const std::string& text, const std::string& pattern) {
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());

    if (m == 0 || n < m) {
        return -1;
    }

    const std::vector<int> table = BuildShiftTable(pattern);

    int i = m - 1;

    while (i < n) {
        int k = i;
        int j = m - 1;

        while (j >= 0 && text[k] == pattern[j]) {
            --k;
            --j;
        }

        if (j < 0) {
            return k + 1;
        }

        const auto c = static_cast<unsigned char>(text[i]);
        i += table[c];
    }

    return -1;
}

std::vector<int> FindAll(const std::string& text, const std::string& pattern,
    int start_pos, int end_pos) {
    std::vector<int> occurrences;
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());

    start_pos = std::max(0, start_pos);
    end_pos = std::min(n - 1, end_pos);

    if (m == 0 || start_pos > end_pos || (end_pos - start_pos + 1) < m) {
        return occurrences;
    }

    const std::vector<int> table = BuildShiftTable(pattern);

    int i = start_pos + m - 1;

    while (i <= end_pos) {
        int k = i;
        int j = m - 1;

        while (j >= 0 && text[k] == pattern[j]) {
            --k;
            --j;
        }

        if (j < 0) {
            occurrences.push_back(k + 1);
        }

        const auto c = static_cast<unsigned char>(text[i]);
        i += table[c];
    }

    return occurrences;
}

std::vector<int> FindAll(const std::string& text, const std::string& pattern) {
    if (text.empty()) {
        return {};
    }
    return FindAll(text, pattern, 0, static_cast<int>(text.size()) - 1);
}