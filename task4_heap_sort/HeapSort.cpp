#include "HeapSort.h"
#include <algorithm>

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