#include "QuickSort.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

bool IsSorted(const int* arr, int size) {
    if (size <= 1) return true;
    if (arr == nullptr) return false;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool IsSorted(const std::vector<int>& arr) {
    return IsSorted(arr.data(), static_cast<int>(arr.size()));
}

void QuickSort(int* a, int l, int r) {
    if (l >= r || a == nullptr) {
        return;
    }

    int i = l;
    int j = r;
    int x = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < x) {
            ++i;
        }
        while (a[j] > x) {
            --j;
        }
        if (i <= j) {
            std::swap(a[i], a[j]);
            ++i;
            --j;
        }
    }

    if (l < j) {
        QuickSort(a, l, j);
    }

    if (i < r) {
        QuickSort(a, i, r);
    }
}

void QuickSort(int* a, int size) {
    if (a == nullptr || size <= 1) {
        return;
    }
    QuickSort(a, 0, size - 1);
}

void QuickSort(std::vector<int>& arr) {
    QuickSort(arr.data(), static_cast<int>(arr.size()));
}

std::vector<int> LoadOrCreateDataset(const std::string& filename, int size, int min_val, int max_val) {
    std::ifstream file(filename);
    if (!file.is_open()) file.open("../task5_quick_sort/" + filename);
    if (!file.is_open()) file.open("../../task5_quick_sort/" + filename);
    
    if (file.is_open()) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            if (!(file >> arr[i])) break;
        }
        file.close();
        return arr;
    }

    std::cout << "Creating " << filename << "...\n";
    std::mt19937 gen(1337 + size + min_val);
    std::uniform_int_distribution<int> dist(min_val, max_val);
    std::vector<int> arr(size);
    std::ofstream out(filename);
    for (int i = 0; i < size; ++i) {
        arr[i] = dist(gen);
        out << arr[i] << " ";
    }
    out.close();
    return arr;
}

double MeasureQuickSortTime(const std::vector<int>& original) {
    double total_ms = 0.0;
    const int runs_count = 3;

    for (int run = 0; run < runs_count; ++run) {
        std::vector<int> copy = original;

        auto start = std::chrono::high_resolution_clock::now();
        QuickSort(copy);
        auto end = std::chrono::high_resolution_clock::now();

        if (!IsSorted(copy)) {
            std::cout << "Error: Array not sorted!\n";
        }

        std::chrono::duration<double, std::milli> duration = end - start;
        total_ms += duration.count();
    }

    return total_ms / runs_count;
}