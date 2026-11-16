#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ShellSort.h"

int main() {
    const int sizes[3] = { 10000, 100000, 1000000 };
    const int min_vals[3] = { -10, -1000, -100000 };
    const int max_vals[3] = { 10, 1000, 100000 };

    const std::string filenames[3][3] = {
     {"dataset_10000_range10.txt", "dataset_10000_range1000.txt", "dataset_10000_range100000.txt"},
     {"dataset_100000_range10.txt", "dataset_100000_range1000.txt", "dataset_100000_range100000.txt"},
     {"dataset_1000000_range10.txt", "dataset_1000000_range1000.txt", "dataset_1000000_range100000.txt"}
    };

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "Size\t\tRange\t\t\tShell(ms)\tKnuth(ms)\tHibbard(ms)\n";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::vector<int> arr = GetOrGenerateArray(filenames[i][j], sizes[i], min_vals[j], max_vals[j]);

            double t_shell = MeasureAverageTime(arr, GetShellGaps(sizes[i]));
            double t_knuth = MeasureAverageTime(arr, GetKnuthGaps(sizes[i]));
            double t_hibbard = MeasureAverageTime(arr, GetHibbardGaps(sizes[i]));

            std::string range_str = "[" + std::to_string(min_vals[j]) + ".." + std::to_string(max_vals[j]) + "]";
            std::cout << sizes[i] << "\t\t" << std::setw(16) << std::left << range_str << "\t"
                << t_shell << "\t\t" << t_knuth << "\t\t" << t_hibbard << "\n";

            
        }
    }

    return 0;
}