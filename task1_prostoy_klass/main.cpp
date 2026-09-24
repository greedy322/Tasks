#include <iostream>
#include "Rectangle.h"

int main() 
{
	Rectangle r1;                           
	Rectangle r2(2.0, 5.0, 4.0, 4.0);        

	std::cout << "r1: " << r1 << "\n";
	std::cout << "r2: " << r2 << "\n\n";

	std::cout << "r2 Area: " << r2.GetArea() << "\n";
	std::cout << "r2 Radius: " << r2.GetCircumradius() << "\n";
	std::cout << "Is r2 square: " << (r2.IsSquare() ? "Yes" : "No") << "\n\n";

	
	Rectangle r3 = r2 * 2.0;
	Rectangle r4 = 0.5 * r2;
	std::cout << "r2 * 2.0: " << r3 << "\n";
	std::cout << "0.5 * r2: " << r4 << "\n";

	return 0;
}