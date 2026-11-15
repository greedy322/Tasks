#include "ShellSort.h"

bool IsSorted(const int* arr, int size) {
    if (arr == nullptr || size <= 1) {
        return true;
    }
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void ShellSort(int* arr, int size) {
    if (arr == nullptr || size <= 1) {
        return;
    }

    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= s && arr[j - s] > temp) {
                arr[j] = arr[j - s];
                j -= s;
            }
            arr[j] = temp;
        }
    }
}