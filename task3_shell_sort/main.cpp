#include <iostream>

#include "ShellSort.h"

int main() {

    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    const int size = 9;

    std::cout << "Initial array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Is sorted before: " << (IsSorted(arr, size) ? "Yes" : "No") << "\n\n";

    ShellSort(arr, size);

    std::cout << "Sorted array:  ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Is sorted after:  " << (IsSorted(arr, size) ? "Yes" : "No") << "\n";

    return 0;
}
//git commit -m "Реализовать базовый алгоритм Шелла и функцию IsSorted " -m "- Настроить сборку task3_shell_sort в CMakeLists.txt`n- Реализовать функцию IsSorted для проверки упорядоченности массива`n- Реализовать классическую сортировку Шелла с шагом n/2 `n- Добавить проверку сортировки на тестовом массиве в main.cpp"