#include <iostream>
#include <vector>

#include "QuickSort.h"

int main() {

	std::vector<int> arr = { 36, 24, 55, 12, 4, 32, 24, 5 };

	std::cout << "Initial array: ";
	for (int x : arr) std::cout << x << " ";
	std::cout << "\n";
	std::cout << "IsSorted before: " << (IsSorted(arr) ? "Yes" : "No") << "\n\n";

	QuickSort(arr);

	std::cout << "Sorted array:  ";
	for (int x : arr) std::cout << x << " ";
	std::cout << "\n";
	std::cout << "IsSorted after:  " << (IsSorted(arr) ? "Yes" : "No") << "\n";

	return 0;
}