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