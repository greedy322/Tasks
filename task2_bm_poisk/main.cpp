#include <iostream>
#include <string>

#include "BoyerMoore.h"

int main() {
    const std::string text =
        "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    const std::string pattern = "tor";

    std::cout << "Text length: " << text.size() << "\n";
    std::cout << "Pattern: \"" << pattern << "\"\n\n";

    int first_idx = FindFirst(text, pattern);
    std::cout << "First occurrence index: " << first_idx << " (expected: 15)\n";

  
    int not_found = FindFirst(text, "cat");
    std::cout << "Search for \"cat\": " << not_found << " (expected: -1)\n";

    return 0;
}