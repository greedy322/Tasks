#pragma once

#include <vector>

bool IsSorted(const int* arr, int size);
bool IsSorted(const std::vector<int>& arr);
void Sift(int* a, int n, int i);

void BuildHeap(int* a, int n);
void HeapSort(int* a, int n);
void HeapSort(std::vector<int>& arr);