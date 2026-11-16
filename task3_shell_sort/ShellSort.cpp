#include "ShellSort.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>


bool IsSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

std::vector<int> GetShellGaps(int n) {
    std::vector<int> gaps;
    for (int h = n / 2; h > 0; h /= 2) {
        gaps.push_back(h);
    }
    return gaps;
}

std::vector<int> GetKnuthGaps(int n) {
    std::vector<int> gaps;
    int h = 1;
    while (h < n) {
        gaps.push_back(h);
        if (h > (2147483647 - 1) / 3) break;
        h = 3 * h + 1;
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}

std::vector<int> GetHibbardGaps(int n) {
    std::vector<int> gaps;
    int k = 1;
    while (true) {
        long long h = (1LL << k) - 1; 
        if (h >= n) break;
        gaps.push_back(static_cast<int>(h));
        ++k;
    }
    if (gaps.empty()) {
        gaps.push_back(1);
    }
    std::reverse(gaps.begin(), gaps.end());
    return gaps;
}

void ShellSort(std::vector<int>& a, const std::vector<int>& gaps) {
    const int n = static_cast<int>(a.size());
    for (int s : gaps) {
        for (int b = 0; b < s; ++b) {
            for (int j = b + s; j < n; j += s) {
                int x = a[j];
                int k = j - s;
                while (k >= 0 && a[k] > x) {
                    a[k + s] = a[k];
                    k -= s;
                }
                a[k + s] = x;
            }
        }
    }
}

std::vector<int> GetOrGenerateArray(const std::string& filename, int size, int min_val, int max_val) {
    std::ifstream check(filename);
    if (!check.is_open()) {
        std::cout << "Generating " << filename << "...\n";
        std::mt19937 gen(1337 + size + min_val);
        std::uniform_int_distribution<int> dist(min_val, max_val);
        std::ofstream fout(filename);
        for (int i = 0; i < size; ++i) {
            fout << dist(gen) << (i + 1 < size ? " " : "\n");
        }
        fout.close();
    }
    else {
        check.close();
    }

    std::vector<int> arr(size);
    std::ifstream fin(filename);
    for (int i = 0; i < size; ++i) {
        fin >> arr[i];
    }
    return arr;
}

double MeasureAverageTime(const std::vector<int>& original, const std::vector<int>& gaps) {
    double total_ms = 0.0;
    for (int run = 0; run < 3; ++run) {
        std::vector<int> copy = original;
        auto start = std::chrono::high_resolution_clock::now();
        ShellSort(copy, gaps);
        auto end = std::chrono::high_resolution_clock::now();

        if (!IsSorted(copy)) {
            std::cout << "Error: Array not sorted!\n";
        }

        std::chrono::duration<double, std::milli> duration = end - start;
        total_ms += duration.count();
    }
    return total_ms / 3.0;
}