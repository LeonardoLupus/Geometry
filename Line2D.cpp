//
// Created by leonid on 22.04.24.
//

#include "Line2D.h"

Line2D::Line2D(const Line2D& line) {
    a = line.getA();
    b = line.getB();
    c = line.getC();
}

Line2D::Line2D(const Point2D &first, const Point2D &second) {
    equationLine(first, second);
}

Line2D::Line2D(const double a, const double b, const double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

auto Line2D::equationLine(const Point2D &first, const Point2D &second) -> void {
    a = second.getY() - first.getY();
    b = first.getX() - second.getX();
    c = first.getX()*(first.getY() - second.getY()) + first.getY()*(second.getX() - first.getX());
}

auto Line2D::Y(double x) const -> double {
    return (a * x + c) / (-b);
}

auto Line2D::X(double y) const -> double {
    return (b * y + c) / (-a);
}

[[maybe_unused]] auto Line2D::getA() const -> double {
    return a;
}

auto Line2D::getB() const -> double {
    return b;
}

auto Line2D::getC() const -> double {
    return c;
}

auto Line2D::getNormal() const -> Line2D {
    return a == 0 ? Line2D{Point2D{a, b}, Point2D{0, -(c/b)}} :  Line2D{Point2D{a, b}, Point2D{-(c/a), 0}};
}

auto Line2D::getNormal(const Point2D& point) const -> Line2D {
    return Line2D{b, -a, (a*point.getY())-(b*point.getX())};
}

auto Line2D::intersection(const Line2D &a, const Line2D &b) -> Point2D {
    double y = -(-(b.getA() * a.getC())/a.getA() + b.getC()) / (b.getB() - b.getA()*a.getB()/a.getA());
    double x = -(a.getB()*y + a.getC()) / a.getA();
    return Point2D{x, y};
}


