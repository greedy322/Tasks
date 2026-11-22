#include "QuickSort.h"

#include <algorithm>

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