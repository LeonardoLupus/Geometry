//
// Created by leonid on 01.03.24.
//

#include "Point2D.h"

#include <cmath>

auto operator+(const Point2D& aPoint, const Point2D& bPoint) -> Point2D {
    return Point2D(aPoint.x + bPoint.x, aPoint.y + bPoint.y);
}

auto operator-(const Point2D& aPoint, const Point2D& bPoint) -> Point2D {
    return Point2D(aPoint.x - bPoint.x, aPoint.y - bPoint.y);
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

Point2D::Point2D(const double radius, const Angel& theta) {
    setPolar(radius, theta);
}

auto Point2D::setXY(const double x, const double y) -> void {
    this->x = x;
    this->y = y;
    calculateCoord();
}

auto Point2D::setPolar(const double radius, const Angel& theta) -> void {
    this->radius = radius;
    this->theta = theta;
    calculateCoord(false);
}

auto Point2D::addX(double x) -> void {
    this->x += x;
    calculateCoord();
}

auto Point2D::addY(double y) -> void {
    this->y += y;
    calculateCoord();
}

auto Point2D::addRadius(double radius) -> void {
    this->radius += radius;
    calculateCoord(false);
}

auto Point2D::addTheta(const Angel &theta) -> void {
    this->theta += theta;
    calculateCoord(false);
}

auto Point2D::getX() const -> const double& {
    return x;
}

auto Point2D::getY() const -> const double& {
    return y;
}

auto Point2D::getRadius() const -> const double& {
    return radius;
}

auto Point2D::getTheta() const -> const Angel& {
    return theta;
}

auto Point2D::isNull() -> const bool {
    return (x== 0 && y == 0) || radius == 0;
}

auto Point2D::calculateCoord(bool xy) -> void {
    if (xy) {
        radius = std::sqrt(x*x + y*y);
        theta = (x / radius * (y < 0?-1:1));
    } else {
        x = radius * std::cos(theta.getRadian());
        y = radius * std::sin(theta.getRadian());
    }
}
