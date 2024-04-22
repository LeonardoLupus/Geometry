//
// Created by leonid on 01.03.24.
//

#include "Vector2D.h"

#include <cmath>

auto operator+(const Vector2D& a, const Vector2D& b)->Vector2D {
    return Vector2D{a.pointStart, a.getEnd() + b.get()};
}

auto operator+(const Vector2D &a, const Angle &b)->Vector2D {
    return Vector2D{b + a.getTheta(), ~a, a.getStart()};
}

auto operator-(const Vector2D& a, const Vector2D& b)->Vector2D {
    return Vector2D{a.pointStart, a.getEnd() - b.get()};
}

auto operator*(const Vector2D &a, double b) -> Vector2D {
    return Vector2D{a.getTheta(), (~a)*b, a.getStart()};
}

auto operator*(const Vector2D &a, const Vector2D &b) -> double {
    return a.getX() * b.getX() + a.getY() * b.getY();
}

auto operator^(const Vector2D &a, const Vector2D &b) -> double {
    return a.getX()*b.getY()-b.getX()*a.getY();
}

auto operator^=(const Vector2D &a, const Vector2D &b) -> int {
    double buf = Point2D::roundPr(a^b, 1);
    if(buf < 0) {return -1;}
    if(buf > 0) {return 1;}
    return 0;
}

auto Vector2D::operator~() const -> const double& {
    return radius;
}

Vector2D::Vector2D() {
    resetToZero(pointStart);
}

Vector2D::Vector2D(const Point2D& direction): Point2D(direction) {
    resetToZero(pointStart);
}

Vector2D::Vector2D(const double x, const double y): Point2D(x, y) {
    resetToZero(pointStart);
}

Vector2D::Vector2D(const Point2D& begin, const Point2D& end): Point2D(calculateDirection(begin, end)){
    pointStart = begin;
}

Vector2D::Vector2D(const Angle &phi, const double length, const Point2D& begin): Point2D(begin + Point2D(length, phi)) {
    pointStart = begin;
}

auto Vector2D::setBegin(const Point2D &begin) -> void {
    pointStart = begin;
}

auto Vector2D::setEnd(const Point2D &end) -> void {
    setPoint(calculateDirection(pointStart, end));
}

auto Vector2D::setDirection(const Point2D &direction) -> void {
    setPoint(direction);
}

auto Vector2D::setRadius(double lengthRadius) -> void {
    radius = lengthRadius;
}

auto Vector2D::getEnd() const -> Point2D {
    return pointStart + get();
}

auto Vector2D::getStart() const -> Point2D {
    return pointStart;
}

[[maybe_unused]] auto Vector2D::AngleBTWVectors(const Vector2D &a, const Vector2D &b) -> Angle {
    return Angle{atan2(a^b, a*b)};
}

[[maybe_unused]] auto Vector2D::isCollinear(const Vector2D &a, const Vector2D &b) -> bool {
    return a.getTheta() == b.getTheta();
}

auto Vector2D::resetToZero(Point2D& point) -> void {
    point.setXY(0, 0);
}

auto Vector2D::calculateDirection(const Point2D &start, const Point2D &end) -> Point2D {
    return Point2D(end - start);
}
