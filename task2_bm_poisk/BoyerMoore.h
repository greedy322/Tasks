#pragma once

#include <string>
#include <vector>

std::vector<int> BuildShiftTable(const std::string& pattern);

int FindFirst(const std::string& text, const std::string& pattern);