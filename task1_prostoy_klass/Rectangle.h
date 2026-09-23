#pragma once

class Rectangle {
public:

	Rectangle();
	Rectangle(double x, double y, double width, double height);


	void Read();
	void Print() const;


	void SetWidth(double width);
	void SetHeight(double height);


	double GetX() const { return x_; }
	double GetY() const { return y_; }
	double GetWidth() const { return width_; }
	double GetHeight() const { return height_; }

	void SetX(double x) { x_ = x; }
	void SetY(double y) { y_ = y; }
	void SetWidth(double width);
	void SetHeight(double height);

	double GetArea() const;

	double GetCircumradius() const;

	bool IsSquare() const;

private:
	double x_;
	double y_;
	double width_;
	double height_;
};