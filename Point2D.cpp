//
// Created by leonid on 01.03.24.
//

#include "Point2D.h"

#include <cmath>

auto operator+(const Point2D& aPoint, const Point2D& bPoint) -> Point2D {
    return {aPoint.x + bPoint.x, aPoint.y + bPoint.y};
}

auto operator-(const Point2D& aPoint, const Point2D& bPoint) -> Point2D {
    return {aPoint.x - bPoint.x, aPoint.y - bPoint.y};
}

auto Point2D::operator=(const Point2D& bPoint) -> Point2D& {
    x = bPoint.x;
    y = bPoint.y;
    radius = bPoint.radius;
    theta = bPoint.theta;
    return *this;
}

Point2D::Point2D() {
    this->x = 0;
    this->y = 0;
    this->radius = 0;
    this->theta = 0;
}

Point2D::Point2D(const Point2D &copy) {
    this->x = copy.x;
    this->y = copy.y;
    this->radius = copy.radius;
    this->theta = copy.theta;
}

Point2D::Point2D(const double x, const double y) {
    setXY(x, y);
}

Point2D::Point2D(const double radius, const Angle& theta) {
    setPolar(radius, theta);
}

auto Point2D::setXY(const double x, const double y) -> void {
    this->x = x;
    this->y = y;
    convertToPolar();
}

auto Point2D::setPolar(const double radius, const Angle& theta) -> void {
    this->radius = radius;
    this->theta = theta;
    convertToCartesian();
}

auto Point2D::addX(double x) -> void {
    this->x += x;
    convertToPolar();
}

auto Point2D::addY(double y) -> void {
    this->y += y;
    convertToPolar();
}

auto Point2D::addRadius(double radius) -> void {
    this->radius += radius;
    convertToCartesian();
}

auto Point2D::addTheta(const Angle &theta) -> void {
    this->theta += theta;
    convertToCartesian();
}

auto Point2D::getX() const -> double {
    return x;
}

auto Point2D::getY() const -> double {
    return y;
}

auto Point2D::getRadius() const -> double {
    return radius;
}

auto Point2D::getTheta() const -> Angle {
    return theta;
}

auto Point2D::isNull() const -> bool {
    return (x== 0 && y == 0) || radius == 0;
}

auto Point2D::convertToCartesian() -> void {
    x = radius * roundPr(std::cos(theta.getRadian()), 10);
    y = radius * roundPr(std::sin(theta.getRadian()), 10);
}

auto Point2D::convertToPolar() -> void {
    radius = std::sqrt(x*x + y*y);
    theta = atan2(y, x);
//    theta = radius == 0 ? 0 : std::acos( x/radius * (y < 0 ? -1 : 1) );
}

auto Point2D::setPoint(const Point2D &point) -> void {
    this->x = point.getX();
    this->x = point.getY();
    this->radius = point.getRadius();
    this->theta = point.getTheta();
}

auto Point2D::get() const -> Point2D {
    return Point2D{x, y};
}

auto Point2D::roundPr(const double number, unsigned int pr) -> double {
    double p = pow(10, pr);
    return (round(number* p) / p);
}


