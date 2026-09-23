#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : x_(0.0), y_(0.0), width_(1.0), height_(1.0) {}

Rectangle::Rectangle(double x, double y, double width, double height)
    : x_(x), y_(y) 
{
    SetWidth(width);
    SetHeight(height);
}

void Rectangle::Read() 
{
    std::cout << "...";
    std::cin >> x_ >> y_;
    std::cout << "... ";
    double w = 0.0;
    double h = 0.0;
    std::cin >> w >> h;
    SetWidth(w);
    SetHeight(h);
}

void Rectangle::Print() const {
    std::cout << "Rectangle[A(" << x_ << ", " << y_ << "), width=" << width_
        << ", height=" << height_ << "]\n";
}


void Rectangle::SetWidth(double width) {
    width_ = (width > 0.0) ? width : 1.0;
}

void Rectangle::SetHeight(double height) {
    height_ = (height > 0.0) ? height : 1.0;
}


double Rectangle::GetArea() const {
    return width_ * height_;
}

double Rectangle::GetCircumradius() const {
    return std::sqrt(width_ * width_ + height_ * height_) / 2.0;
}

bool Rectangle::IsSquare() const {
    const double kEpsilon = 1.0e-9;
    return std::abs(width_ - height_) < kEpsilon;
}