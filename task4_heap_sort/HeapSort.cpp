#include "HeapSort.h"

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