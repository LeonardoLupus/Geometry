//
// Created by leonid on 01.03.24.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "Point2D.h"


class Vector2D {
public:
    friend auto operator+(const Vector2D& a, const Vector2D& b)->Vector2D;
    friend auto operator+(const Vector2D& a, const Angle& b)->Vector2D;
    friend auto operator-(const Vector2D& a, const Vector2D& b)->Vector2D;
    friend auto operator*(const Vector2D& a, double b)->Vector2D;
    friend auto operator*(const Vector2D& a, const Vector2D& b)->double;
    friend auto operator^(const Vector2D& a, const Vector2D& b)->double;

    auto operator~()const -> const double&;

    Vector2D();
    explicit Vector2D(const Point2D& end);
    Vector2D(double x, double y);
    Vector2D(const Point2D& begin, const Point2D& end);
    Vector2D(const Angle& phi, double length, Point2D begin = {0, 0});

    auto setBegin(const Point2D& begin)->void;
    auto setEnd(const Point2D& end)->void;
    auto setDirection(const Point2D&)->void;
    auto setLength(double lengthRadius)->void;
    auto addLength(double lengthRadius)->void;

    auto getAngle()const -> const Angle&;
    auto getLength()const -> const double;
    auto getEnd()const -> const Point2D&;
    auto getStart()const -> const Point2D&;
    auto getVector()const -> const Point2D&;
    auto getVectorX()const -> const double&;
    auto getVectorY()const -> const double&;

    static auto AngleVectors(const Vector2D& a, const Vector2D& b) -> const Angle;
    static auto isCollinear(const Vector2D& a, const Vector2D& b) -> const bool;
    static auto onOneLine(const Point2D& a, const Point2D& b, const Point2D& c) -> const bool;

private:
    auto resetToZero(Point2D& point)->void;
    auto calculateDirection()->void;
    auto calculateEnd()->void;

    Point2D pointStart;
    Point2D pointEnd;
    Point2D direction;
};



#endif //VECTOR2D_H
