#pragma once

#include <string>
#include <vector>

bool IsSorted(const int* arr, int size);
bool IsSorted(const std::vector<int>& arr);

void QuickSort(int* a, int l, int r);
void QuickSort(int* a, int size);
void QuickSort(std::vector<int>& arr);

std::vector<int> LoadOrCreateDataset(const std::string& filename, int size, int min_val, int max_val);
double MeasureQuickSortTime(const std::vector<int>& original);