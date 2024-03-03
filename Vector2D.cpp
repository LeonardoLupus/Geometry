//
// Created by leonid on 01.03.24.
//

#include "Vector2D.h"

#include <cmath>

auto operator+(const Vector2D& a, const Vector2D& b)->Vector2D {
    return Vector2D(a.pointStart, a.pointEnd + b.direction);
}

auto operator+(const Vector2D &a, const Angel &b)->Vector2D {
    return Vector2D{b + a.direction.getTheta(), a.direction.getRadius(), a.getStart()};
}

auto operator-(const Vector2D& a, const Vector2D& b)->Vector2D {
    return Vector2D(a.pointStart, a.pointEnd - b.direction);
}

auto operator*(const Vector2D &a, double b) -> Vector2D {
    return Vector2D(a.getStart(), a.getStart() + Point2D(a.getVectorX() * b, a.getVectorY() * b));
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

Vector2D::Vector2D(const Angel &phi, const double length, Point2D begin) {
    pointStart = begin;
    direction.setXY(length* cos(phi.getRadian()), length* sin(phi.getRadian()));
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

auto Vector2D::getAngel() const -> const Angel & {
    return direction.getTheta();
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

auto Vector2D::angelVectors(const Vector2D &a, const Vector2D &b) -> const Angel {
    return Angel{atan2(a^b, a*b)};
}

auto Vector2D::isCollinear(const Vector2D &a, const Vector2D &b) -> const bool {
    return sin(angelVectors(a, b).getRadian()) == 0;
}

auto Vector2D::onOneLine(const Point2D &a, const Point2D &b, const Point2D &c) -> const bool {
    Vector2D z(a, b);
    Vector2D w(b, c);
    return isCollinear(z, w);
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
