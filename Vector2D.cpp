//
// Created by leonid on 01.03.24.
//

#include "Vector2D.h"

#include <cmath>

auto operator+(const Vector2D& a, const Vector2D& b)->Vector2D {
    return Vector2D(a.pointStart, a.pointEnd + b.direction);
}

auto operator+(const Vector2D &a, const Angle &b)->Vector2D {
    return Vector2D{b + a.getAngle(), ~a, a.getStart()};
}

auto operator-(const Vector2D& a, const Vector2D& b)->Vector2D {
    return Vector2D(a.pointStart, a.pointEnd - b.direction);
}

auto operator*(const Vector2D &a, double b) -> Vector2D {
    return Vector2D(a.getAngle(), (~a)*b, a.getStart());
}

auto operator*(const Vector2D &a, const Vector2D &b) -> double {
    return a.getVectorX() * b.getVectorX() + a.getVectorY() * b.getVectorY();
}

auto operator^(const Vector2D &a, const Vector2D &b) -> double {
    return a.getVectorX()*b.getVectorY()-b.getVectorX()*a.getVectorY();
}

auto Vector2D::operator~() const -> const double& {
    return direction.getRadius();
}

Vector2D::Vector2D() {
    resetToZero(pointStart);
    resetToZero(pointEnd);
    resetToZero(direction);
}

Vector2D::Vector2D(const Point2D& end) {
    resetToZero(pointStart);
    pointEnd = end;
    direction = end;
}

Vector2D::Vector2D(const double x, const double y) {
    resetToZero(pointStart);
    pointEnd = {x, y};
    direction = {x, y};
}

Vector2D::Vector2D(const Point2D& begin, const Point2D& end) {
    pointStart = begin;
    pointEnd = end;
    calculateDirection();
}

Vector2D::Vector2D(const Angle &phi, const double length, Point2D begin) {
    pointStart = begin;
    direction.setPolar(length,phi);
    calculateEnd();
}

auto Vector2D::setBegin(const Point2D &begin) -> void {
    pointStart = begin;
    calculateDirection();
}

auto Vector2D::setEnd(const Point2D &end) -> void {
    pointEnd = end;
    calculateDirection();
}

auto Vector2D::setDirection(const Point2D &direction) -> void {
    this->direction = direction;
    calculateEnd();
}

auto Vector2D::setLength(double lengthRadius) -> void {
    pointEnd.setPolar(lengthRadius, pointEnd.getTheta());
    calculateDirection();
}

auto Vector2D::addLength(double lengthRadius) -> void {
    pointEnd.addRadius(lengthRadius - pointEnd.getRadius());
    calculateDirection();
}

auto Vector2D::getAngle() const -> const Angle & {
    return direction.getTheta();
}

auto Vector2D::getLength() const -> const double {
    return direction.getRadius();
}

auto Vector2D::getEnd() const -> const Point2D & {
    return pointEnd;
}

auto Vector2D::getStart() const -> const Point2D & {
    return pointStart;
}

auto Vector2D::getVector() const -> const Point2D & {
    return direction;
}

auto Vector2D::getVectorX() const -> const double & {
    return direction.getX();
}

auto Vector2D::getVectorY() const -> const double & {
    return direction.getY();
}

auto Vector2D::AngleVectors(const Vector2D &a, const Vector2D &b) -> const Angle {
    return Angle{atan2(a^b, a*b)};
}

auto Vector2D::isCollinear(const Vector2D &a, const Vector2D &b) -> const bool {
    return sin(AngleVectors(a, b).getRadian()) == 0;
}

auto Vector2D::resetToZero(Point2D& point) -> void {
    point.setXY(0, 0);
}

auto Vector2D::calculateEnd() -> void {
    pointEnd = pointStart + direction;
}

auto Vector2D::calculateDirection() -> void {
    direction = pointEnd - pointStart;
}
