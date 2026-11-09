#include <iostream>

#include "DynamicArray.h"

int main() {
	std::cout << "DynamicArray\n\n";

	int raw_data[] = { 5, 2, 8, 1, 9 };
	DynamicArray arr1(raw_data, 5);
	std::cout << "Initial arr1: " << arr1 << " (size: " << arr1.GetSize() << ")\n\n";

	arr1.Insert(2, 99);
	std::cout << "Insert 99 at index 2: " << arr1 << "\n";
	std::cout << "Invalid insert: " << (arr1.Insert(100, 7) ? "true" : "false") << "\n\n";

	arr1.RemoveAt(2); 
	std::cout << "RemoveAt index 2: " << arr1 << "\n\n";

	std::cout << "Find 8: index " << arr1.Find(8) << "\n";
	std::cout << "Find 100: index " << arr1.Find(100) << "\n";
	arr1.Remove(8);
	std::cout << "Remove value 8: " << arr1 << "\n\n";

	arr1.Sort();
	std::cout << "Sorted arr1: " << arr1 << "\n\n";

	DynamicArray arr2 = arr1; 
	DynamicArray arr3;
	arr3 = arr1;             
	std::cout << "Copy arr2: " << arr2 << "\n";
	std::cout << "Assigned arr3: " << arr3 << "\n\n";

	int other_raw[] = { 10, 20, 30 };
	DynamicArray arr4(other_raw, 3);
	std::cout << "Before swap: arr1 = " << arr1 << ", arr4 = " << arr4 << "\n";
	arr1.Swap(arr4);
	std::cout << "After swap:  arr1 = " << arr1 << ", arr4 = " << arr4 << "\n";


	return 0;
}