#pragma once

#include <string>
#include <vector>


bool IsSorted(const std::vector<int>& arr);

std::vector<int> GetShellGaps(int n);
std::vector<int> GetKnuthGaps(int n);
std::vector<int> GetHibbardGaps(int n);

void ShellSort(std::vector<int>& a, const std::vector<int>& gaps);

std::vector<int> GetOrGenerateArray(const std::string& filename, int size, int min_val, int max_val);

double MeasureAverageTime(const std::vector<int>& original, const std::vector<int>& gaps);
