#pragma once

class Rectangle {
public:

	Rectangle();
	Rectangle(double x, double y, double width, double height);


	void Read();


	void SetWidth(double width);
	void SetHeight(double height);


	double GetX() const { return x_; }
	double GetY() const { return y_; }
	double GetWidth() const { return width_; }
	double GetHeight() const { return height_; }

private:
	double x_;
	double y_;
	double width_;
	double height_;
};