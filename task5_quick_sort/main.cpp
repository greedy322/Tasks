#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

#include "QuickSort.h"

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
    std::cout << "Size\t\tRange\t\t\tQuickSort(ms)\tStatus\n";
    std::cout << "------------------------------------------------------------------\n";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::vector<int> arr = LoadOrCreateDataset(filenames[i][j], sizes[i], min_vals[j], max_vals[j]);

            double avg_time = MeasureQuickSortTime(arr);

            std::string range_str = "[" + std::to_string(min_vals[j]) + ".." + std::to_string(max_vals[j]) + "]";
            std::cout << sizes[i] << "\t\t" << std::setw(16) << std::left << range_str << "\t"
                << avg_time << " ms\tOK\n";
        }
        std::cout << "------------------------------------------------------------------\n";
    }

    std::cout << "\nCompleted\n";
    return 0;
}