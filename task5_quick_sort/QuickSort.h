#pragma once

#include <vector>

bool IsSorted(const int* arr, int size);
bool IsSorted(const std::vector<int>& arr);

void QuickSort(int* a, int l, int r);
void QuickSort(int* a, int size);
void QuickSort(std::vector<int>& arr);