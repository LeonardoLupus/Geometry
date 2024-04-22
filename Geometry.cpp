//
// Created by leonid on 14.03.24.
//

// #include "Matrix.h"
#include "Geometry.h"


auto Geometry::onOneLine(const Point2D &a, const Point2D &b, const Point2D &c) -> bool {
    const Vector2D z(a, b);
    const Vector2D w(b, c);
    return Vector2D::isCollinear(z, w);
}

auto Geometry::isPointRigthOfVector(const Point2D &point, const Vector2D &vctr) -> bool {
    const Vector2D subVector(vctr.getStart(), point);
    return 0 > (vctr^subVector);
}

auto Geometry::areaOfTriangle(const Point2D &a, const Point2D &b, const Point2D &c) -> double {
    const Vector2D subVectorA(a, b);
    const Vector2D subVectorB(a, c);
    if((subVectorA ^ subVectorB) < 0) {
        return (subVectorA ^ subVectorB)*(-1) / 2;
    }
    return (subVectorA ^ subVectorB) / 2;
}

auto Geometry::isLineIntersect(const Vector2D &a, const Vector2D &b) -> bool {
    return !Vector2D::isCollinear(a, b);
}

auto Geometry::isSegmentIntersect(const Vector2D &a, const Vector2D &b) -> bool {
    return 0;
}

auto Geometry::orientedAreaOfTriangle(const Vector2D &a, const Vector2D &b) -> double {
    return (a^b) / 2;
}
