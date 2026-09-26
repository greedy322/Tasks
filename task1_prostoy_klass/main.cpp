#include <iostream>
#include "Rectangle.h"

int main() 
{
	std::cout << "Testing Rectangle: \n\n";

	Rectangle r1(1.0, 5.0, 4.0, 2.0);
	Rectangle r2(10.0, 20.0, 4.0, 2.0);
	Rectangle r3(1.0, 5.0, 5.0, 2.0);

	std::cout << "r1: " << r1 << "\n";
	std::cout << "r2: " << r2 << "\n";
	std::cout << "r3: " << r3 << "\n\n";

	std::cout << "r1 == r2: " << (r1 == r2 ? "true" : "false") << "\n";
	std::cout << "r1 == r3: " << (r1 == r3 ? "true" : "false") << "\n";
	std::cout << "r1 != r3: " << (r1 != r3 ? "true" : "false") << "\n\n";

	std::cout << "r1 in Q1: " << (r1.IsInFirstQuadrant() ? "yes" : "no") << "\n";

	Rectangle r4(1.0, 1.0, 4.0, 3.0);
	std::cout << "r4: " << r4 << "\n";
	std::cout << "r4 in Q1: " << (r4.IsInFirstQuadrant() ? "yes" : "no") << "\n";


	return 0;
}