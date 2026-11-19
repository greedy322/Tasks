#include "HeapSort.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

bool IsSorted(const int* arr, int size) {
    if (arr == nullptr || size <= 1) return true;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

bool IsSorted(const std::vector<int>& arr) {
    return IsSorted(arr.data(), static_cast<int>(arr.size()));
}

void Sift(int* a, int n, int i) {
    int x = a[i];
    int j = 2 * i + 1;

    while (j < n) {
        if (j + 1 < n && a[j + 1] > a[j]) {
            ++j;
        }
        if (x >= a[j]) {
            break;
        }
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void BuildHeap(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        Sift(a, n, i);
    }
}

void HeapSort(int* a, int n) {
    if (a == nullptr || n <= 1) return;
    BuildHeap(a, n);
    for (int i = n - 1; i > 0; --i) {
        std::swap(a[0], a[i]);
        Sift(a, i, 0);
    }
}

void HeapSort(std::vector<int>& arr) {
    HeapSort(arr.data(), static_cast<int>(arr.size()));
}

std::vector<int> LoadOrCreateDataset(const std::string& filename, int size, int min_val, int max_val) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        file.open("../task4_heap_sort/" + filename);
    }
    if (!file.is_open()) {
        file.open("../../task4_heap_sort/" + filename);
    }

    if (file.is_open()) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            file >> arr[i];
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

double MeasureHeapSortTime(const std::vector<int>& original) {
    double total_ms = 0.0;
    const int runs_count = 3;

    for (int run = 0; run < runs_count; ++run) {
        std::vector<int> copy = original;

        auto start = std::chrono::high_resolution_clock::now();
        HeapSort(copy);
        auto end = std::chrono::high_resolution_clock::now();

        if (!IsSorted(copy)) {
            std::cout << "Error: Array not sorted!\n";
        }

        std::chrono::duration<double, std::milli> duration = end - start;
        total_ms += duration.count();
    }

    return total_ms / runs_count;
}