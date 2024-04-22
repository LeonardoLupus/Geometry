//
// Created by leonid on 01.03.24.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "Point2D.h"


class Vector2D: public Point2D {
public:
    friend auto operator+(const Vector2D& a, const Vector2D& b)->Vector2D;
    friend auto operator+(const Vector2D& a, const Angle& b)->Vector2D;
    friend auto operator-(const Vector2D& a, const Vector2D& b)->Vector2D;
    friend auto operator*(const Vector2D& a, double b)->Vector2D;
    friend auto operator*(const Vector2D& a, const Vector2D& b)->double;
    friend auto operator^(const Vector2D& a, const Vector2D& b)->double;
    friend auto operator^=(const Vector2D& a, const Vector2D& b)->int;

    auto operator~()const -> const double&;

    Vector2D();
    explicit Vector2D(const Point2D& end);
    Vector2D(double x, double y);
    Vector2D(const Point2D& begin, const Point2D& end);
    Vector2D(const Angle& phi, double length, const Point2D& begin = {0, 0});

    auto setBegin(const Point2D& begin)->void;
    auto setEnd(const Point2D& end)->void;
    auto setDirection(const Point2D&)->void;
    auto setRadius(double lengthRadius)->void;

    [[nodiscard]] auto getEnd()const -> Point2D;
    [[nodiscard]] auto getStart()const -> Point2D;

    [[maybe_unused]] static auto AngleBTWVectors(const Vector2D& a, const Vector2D& b) -> Angle;

    [[maybe_unused]] static auto isCollinear(const Vector2D& a, const Vector2D& b) -> bool;

private:
    static auto calculateDirection(const Point2D& start, const Point2D& end) -> Point2D;
    auto resetToZero(Point2D& point)->void;

    Point2D pointStart;
};



#endif //VECTOR2D_H
