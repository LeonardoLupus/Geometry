//
// Created by leonid on 22.04.24.
//

#ifndef GEOMETRY_LINE2D_H
#define GEOMETRY_LINE2D_H

#include "Point2D.h"

class Line2D {
public:
    Line2D() = default;
    Line2D(const Line2D& line);
    Line2D(const Point2D& a, const Point2D& b);
    Line2D(double a, double b, double c);

    [[nodiscard]] auto Y(double x) const -> double;
    [[nodiscard]] auto X(double y) const -> double;

    [[nodiscard]] auto getA() const -> double;
    [[nodiscard]] auto getB() const -> double;
    [[nodiscard]] auto getC() const -> double;
    [[nodiscard]] auto getNormal() const -> Line2D;
    [[nodiscard]] auto getNormal(const Point2D& point) const -> Line2D;

    static auto intersection(const Line2D& a, const Line2D& b) -> Point2D;

private:
    auto equationLine(const Point2D &first, const Point2D &second) -> void;

    double a{}, b{}, c{};
};


#endif //GEOMETRY_LINE2D_H
