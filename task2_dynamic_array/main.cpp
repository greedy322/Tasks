#include <iostream>
#include <utility>

#include "DynamicArray.h"

int main() {

    std::cout << "1. (Basics, Sort, Insert/Remove) \n\n";
    int raw[] = { 50, 20, 80, 10, 90 };
    DynamicArray arr1(raw, 5);
    std::cout << "Initial arr1: " << arr1 << " (size: " << arr1.GetSize() << ")\n";

    arr1.Insert(2, 99); 
    std::cout << "Insert 99 at index 2: " << arr1 << "\n";

    arr1.RemoveAt(2);   
    std::cout << "RemoveAt index 2:    " << arr1 << "\n";

    std::cout << "Find 80: index " << arr1.Find(80) << "\n";

    arr1.Sort();        
    std::cout << "Sorted arr1:         " << arr1 << "\n\n\n";

    std::cout << "2. (Min/Max, RemoveAll, +, +=, ==)\n\n";
    int raw_dup[] = { 7, 3, 7, 9, 7, 1 };
    DynamicArray arr2(raw_dup, 6);
    std::cout << "arr2 with duplicates: " << arr2 << "\n";
    std::cout << "Min: " << arr2.GetMin() << ", Max: " << arr2.GetMax() << "\n";

    arr2.RemoveAll(7);  
    std::cout << "After RemoveAll(7):   " << arr2 << "\n";

    arr2 += 100;       
    std::cout << "arr2 += 100:          " << arr2 << "\n";

    DynamicArray sum = arr1 + arr2; 
    std::cout << "arr1 + arr2:          " << sum << "\n";
    std::cout << "arr1 == arr2:         " << (arr1 == arr2 ? "true" : "false") << "\n\n\n";

    std::cout << "3. (Iterators, Erase range, Move)\n\n";
    std::cout << "Range-based for sum:  ";
    for (int x : sum) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    auto it = sum.begin();
    ++it;
    ++it;
    sum.Insert(it, 777);
    std::cout << "Insert 777 before 3rd: " << sum << "\n";

    it = sum.begin();
    ++it;
    ++it;
    sum.Erase(it);
    std::cout << "Erase 777 by it:       " << sum << "\n";

    auto first = sum.begin();
    ++first;
    auto last = first;
    ++last;
    ++last;
    sum.Erase(first, last);
    std::cout << "Erase range (2 items): " << sum << "\n";

    DynamicArray donor(raw, 3);
    std::cout << "Donor before move:     " << donor << "\n";
    DynamicArray receiver = std::move(donor);
    std::cout << "Receiver after move:   " << receiver << "\n";
    std::cout << "Donor after move:      " << donor << " (size: " << donor.GetSize() << ")\n";

    return 0;
}