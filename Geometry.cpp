//
// Created by leonid on 14.03.24.
//

#include "Matrix.h"
#include "Geometry.h"

#include <cmath>

auto Geometry::onOneLine(const Point2D &a, const Point2D &b, const Point2D &c) -> const bool {
    const Vector2D z(a, b);
    const Vector2D w(b, c);
    return Vector2D::isCollinear(z, w);
}
