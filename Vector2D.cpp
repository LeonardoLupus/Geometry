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
    double buf = a^b;
    if(buf < 0) {return -1;}
    if(buf > 0) {return 1;}
    return 0;
}

auto Vector2D::operator~() const -> double {
    return radius;
}

auto Vector2D::operator-() const -> Vector2D {
//    return Vector2D{pointStart, Point2D{-x, -y}};
    return Vector2D{getEnd(), getStart()};
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
    convertToCartesian();
}

auto Vector2D::parallelTransfer(double direction) -> Vector2D {
    Vector2D n = getNormalUnit();
    n.setRadius(std::abs(direction));
    n = direction < 0? -n : n;
    return Vector2D{pointStart + n.get(), getEnd() + n.get()};
}

auto Vector2D::transfer(const Vector2D& direction) -> Vector2D {
    return Vector2D{pointStart + direction.get(), get() + direction.get()};
}

auto Vector2D::getEnd() const -> Point2D {
    return pointStart + get();
}

auto Vector2D::getStart() const -> Point2D {
    return pointStart;
}

auto Vector2D::getNormal() const -> Vector2D {
    return Vector2D{pointStart, Point2D{y, -x}};
}

auto Vector2D::getNormalUnit() const -> Vector2D {
    return Vector2D{pointStart, Point2D{y/radius, -x/radius}};
}

auto Vector2D::angleBTWVectors(const Vector2D &a, const Vector2D &b) -> Angle {
    return Angle{atan2(a^b, a*b)};
}

auto Vector2D::isCollinear(const Vector2D &a, const Vector2D &b) -> bool {
    return a.getTheta() == b.getTheta() || Angle(a.getTheta() + Angle(PI)) == b.getTheta();
}

auto Vector2D::isIntersectionLines(const Vector2D &a, const Vector2D &b) -> bool {
    return !isCollinear(a, b);
}

auto Vector2D::intersectionLinesPoint(const Vector2D &a, const Vector2D &b) -> Point2D {
    return Line2D::intersection(Line2D{a.getStart(), a.getEnd()}, Line2D(b.getStart(), b.getEnd()));
}

auto Vector2D::resetToZero(Point2D& point) -> void {
    point.setXY(0, 0);
}

auto Vector2D::calculateDirection(const Point2D &start, const Point2D &end) -> Point2D {
    return Point2D(end - start);
}

auto Vector2D::intersectionSegmentsPoint(const Vector2D &a, const Vector2D &b) -> Point2D {
    if(isIntersectionSegments(a, b)) {
        return intersectionLinesPoint(a, b);
    }
    return errorPoint();
}

auto Vector2D::distancePointToLine(const Point2D& point, const Vector2D &line) -> double {
    Vector2D subVector(point - line.getStart());
    return std::abs((subVector^line) / (~line));
}

auto Vector2D::distancePointToSegment(const Point2D &point, const Vector2D &line) -> double {
    Vector2D subVectorFirst(line.getStart(), point);
    Vector2D subVectorSecond(line.getEnd(), point);
    if (line*subVectorFirst >= 0 && subVectorSecond*(-line) >= 0) {
        return distancePointToLine(point, line);
    }
    return subVectorFirst.getRadius() < subVectorSecond.getRadius() ? subVectorFirst.getRadius() : subVectorSecond.getRadius();
}

auto Vector2D::isIntersectionSegments(const Vector2D &a, const Vector2D &b) -> bool {
    if(((a^=Vector2D{a.getStart(), b.getStart()}) * (a^=Vector2D{a.getStart(), b.getEnd()})) <= 0 &&
        ((b^=Vector2D{b.getStart(), a.getStart()}) * (b^=Vector2D{b.getStart(), a.getEnd()})) <= 0) {
        return true;
    }
    return false;
}





