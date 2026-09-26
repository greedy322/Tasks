#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(const double x, const double y, const double width, const double height)
    : x_(x), y_(y) 
{
    SetWidth(width);
    SetHeight(height);
}

void Rectangle::SetWidth(const double width) {
    width_ = (width > 0.0) ? width : 1.0;
}

void Rectangle::SetHeight(const double height) {
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

std::istream& operator>>(std::istream& is, Rectangle& rect) {
    double x, y, width, height;
    is >> x >> y >> width >> height;
    rect.SetX(x);
    rect.SetY(y);
    rect.SetWidth(width);
    rect.SetHeight(height);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Rectangle[A(" << rect.GetX() << ", " << rect.GetY()
        << "), width=" << rect.GetWidth()
        << ", height=" << rect.GetHeight() << "]";
    return os;
}

Rectangle operator*(const Rectangle& rect, const double scale) {
    const double s = (scale > 0.0) ? scale : 1.0;
    return Rectangle(rect.GetX(), rect.GetY(), rect.GetWidth() * s, rect.GetHeight() * s);
}

Rectangle operator*(const double scale, const Rectangle& rect) {
    return rect * scale;
}

bool Rectangle::IsInFirstQuadrant() const {
    return (x_ >= 0.0) && ((y_ - height_) >= 0.0);
}

bool operator==(const Rectangle& r1, const Rectangle& r2) {
    const double kEpsilon = 1.0e-9;
    return (std::abs(r1.GetWidth() - r2.GetWidth()) < kEpsilon) &&
        (std::abs(r1.GetHeight() - r2.GetHeight()) < kEpsilon);
}

bool operator!=(const Rectangle& r1, const Rectangle& r2) {
    return !(r1 == r2);
}