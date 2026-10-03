#include <iostream>
#include <string>
#include <vector>


#include "BoyerMoore.h"

int main() {
    const std::string text =
        "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    const std::string pattern = "tor";

    std::cout << "Boyer-Moore Search Tests\n\n";

    std::cout << "FindFirst: " << FindFirst(text, pattern) << " (expected 15)\n\n";

    std::cout << "FindAll: ";
    for (int idx : FindAll(text, pattern)) {
        std::cout << idx << " ";
    }
    std::cout << "\nExpected: 15 30 38 89\n\n";

    std::cout << "FindAll(0, 91): ";
    for (int idx : FindAll(text, pattern, 0, 91)) {
        std::cout << idx << " ";
    }
    std::cout << "\nExpected:       15 30 38 89\n\n";

    std::cout << "FindAll(17, 91): ";
    for (int idx : FindAll(text, pattern, 17, 91)) {
        std::cout << idx << " ";
    }
    std::cout << "\nExpected:        30 38 89\n\n";

    std::cout << "FindAll(28, 36): ";
    for (int idx : FindAll(text, pattern, 28, 36)) {
        std::cout << idx << " ";
    }
    std::cout << "\nExpected:        30\n";

    return 0;
}