#pragma once
#include <iostream>

class Rectangle {
public:

	Rectangle() = default;;
	Rectangle(const double x, const double y, const double width, const double height);

	double GetX() const { return x_; }
	double GetY() const { return y_; }
	double GetWidth() const { return width_; }
	double GetHeight() const { return height_; }

	void SetX(const double x) { x_ = x; }
	void SetY(const double y) { y_ = y; }
	void SetWidth(const double width);
		void SetHeight(const double height);

	double GetArea() const;

	double GetCircumradius() const;

	bool IsSquare() const;

private:
	double x_ = 0.0;
	double y_ = 0.0;
	double width_ = 1.0;
	double height_ = 1.0;
};

std::istream& operator>>(std::istream& is, Rectangle& rect);
std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

Rectangle operator*(const Rectangle& rect, const double scale);
Rectangle operator*(const double scale, const Rectangle& rect);

