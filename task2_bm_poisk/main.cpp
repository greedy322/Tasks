#include <iostream>
#include <string>
#include <vector>


#include "BoyerMoore.h"

int main() {
    const std::string text =
        "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    const std::string pattern = "tor";

    std::cout << "Text length: " << text.size() << "\n";
    std::cout << "Pattern: \"" << pattern << "\"\n\n";

    int first_idx = FindFirst(text, pattern);
    std::cout << "First occurrence: " << first_idx << " (expected: 15)\n";

  
    std::vector<int> all_indices = FindAll(text, pattern);

    std::cout << "All occurrences (count = " << all_indices.size() << "): [";
    for (size_t i = 0; i < all_indices.size(); ++i) {
        std::cout << all_indices[i] << (i + 1 < all_indices.size() ? ", " : "");
    }
    std::cout << "]\n";
    std::cout << "Expected: [15, 30, 38, 89]\n";

    return 0;
}