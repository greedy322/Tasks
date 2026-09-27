#include <iostream>
#include "Rectangle.h"

int main() 
{
	std::cout << "Testing Rectangle: \n\n";

	Rectangle r1(0.0, 4.0, 4.0, 4.0);
	Rectangle r2(2.0, 6.0, 4.0, 4.0);
	Rectangle r3(10.0, 10.0, 2.0, 2.0);
	Rectangle r4(1.0, 1.0, 4.0, 3.0);

	std::cout << "r1: " << r1 << "\n";
	std::cout << "r2: " << r2 << "\n";
	std::cout << "r3: " << r3 << "\n\n";

	std::cout << "r1 Area: " << r1.GetArea() << "\n";
	std::cout << "r1 Radius: " << r1.GetCircumradius() << "\n";
	std::cout << "r1 is square: " << (r1.IsSquare() ? "yes" : "no") << "\n\n";

	Rectangle scaled = r1 * 2.0;
	std::cout << "r1 * 2: " << scaled << "\n\n";

	std::cout << "r1 == r2: " << (r1 == r2 ? "true" : "false") << "\n";
	std::cout << "r1 == r3: " << (r1 == r3 ? "true" : "false") << "\n";
	std::cout << "r1 != r3: " << (r1 != r3 ? "true" : "false") << "\n\n";

	std::cout << "r1 in Q1: " << (r1.IsInFirstQuadrant() ? "yes" : "no") << "\n";
	std::cout << "r4 in Q1: " << (r4.IsInFirstQuadrant() ? "yes" : "no") << "\n\n";

	std::cout << "r1 intersects r2: " << (r1.Intersects(r2) ? "yes" : "no") << "\n";
	std::cout << "r1 intersects r3: " << (r1.Intersects(r3) ? "yes" : "no") << "\n\n";

	std::cout << "r1 intersects line (y = 2): "
		<< (r1.IntersectsLine(0.0, 1.0, -2.0) ? "yes" : "no") << "\n";

	std::cout << "r1 intersects line (y = 10): "
		<< (r1.IntersectsLine(0.0, 1.0, -10.0) ? "yes" : "no") << "\n";

	return 0;
}