//
// Created by leonid on 01.03.24.
//

#ifndef POINT2D_H
#define POINT2D_H

#include "Angel.h"

class Point2D {
public:
    Point2D();
    Point2D(const Point2D& copy);
    Point2D(double x, double y);
    Point2D(double radius, const Angel& theta);

    friend auto operator+(const Point2D& aPoint, const Point2D& bPoint)->Point2D;
    friend auto operator-(const Point2D& aPoint, const Point2D& bPoint)->Point2D;
    auto operator=(const Point2D& bPoint)->Point2D&;

    auto setXY(double x, double y)->void;
    auto setPolar(double radius, const Angel& theta)->void;
    auto addX(double x)->void;
    auto addY(double y)->void;
    auto addRadius(double radius)->void;
    auto addTheta(const Angel& theta)->void;

    auto getX()const->const double&;
    auto getY()const->const double&;
    auto getRadius()const->const double&;
    auto getTheta()const->const Angel&;

    auto isNull()-> const bool;

private:
    auto calculateCoord(bool xy= true)->void;

    double x;
    double y;
    double radius;
    Angel theta;
};

#endif //POINT2D_H
