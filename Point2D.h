//
// Created by leonid on 01.03.24.
//

#ifndef POINT2D_H
#define POINT2D_H

#include "Angle.h"

const double MAX_DOUBLE = 1.79769e+308;
const unsigned int PRECISION = 10;

class Point2D {
public:
    Point2D();
    Point2D(const Point2D& copy);
    Point2D(double x, double y);
    Point2D(double radius, const Angle& theta);

    friend auto operator+(const Point2D& aPoint, const Point2D& bPoint)->Point2D;
    friend auto operator-(const Point2D& aPoint, const Point2D& bPoint)->Point2D;
    auto operator=(const Point2D& bPoint) ->Point2D&;

    auto setPoint(const Point2D& point)->void;
    auto setXY(double x, double y)->void;
    auto setPolar(double radius, const Angle& theta)->void;
    auto addX(double x)->void;
    auto addY(double y)->void;
    auto addRadius(double radius)->void;
    auto addTheta(const Angle& theta)->void;

    [[nodiscard]] auto get()const->Point2D;
    [[nodiscard]] auto getX()const-> double;
    [[nodiscard]] auto getY()const-> double;
    [[nodiscard]] auto getRadius()const-> double;
    [[nodiscard]] auto getTheta() const -> Angle;
    [[nodiscard]] auto getRadian() const -> double;

    [[nodiscard]] auto isNull() const -> bool;
    static auto roundPr(double number, unsigned int pr = PRECISION)->double;
    static auto errorPoint() -> Point2D;

protected:
    auto convertToCartesian()->void;
    auto convertToPolar()->void;

    double x;
    double y;
    double radius;
    Angle theta;
};

#endif //POINT2D_H
