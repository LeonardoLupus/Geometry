//
// Created by leonid on 14.03.24.
//
#pragma once

#include "Vector2D.h"

class Geometry {
public:
    static auto onOneLine(const Point2D& a, const Point2D& b, const Point2D& c) -> bool;
    static auto isPointRigthOfVector(const Point2D& point, const Vector2D& vctr) -> bool;
    static auto areaOfTriangle(const Point2D& a, const Point2D& b, const Point2D& c) -> double;
    static auto isLineIntersect(const Vector2D& a, const Vector2D& b) -> bool;
    static auto isSegmentIntersect(const Vector2D& a, const Vector2D& b) -> bool;

private:
    static auto orientedAreaOfTriangle(const Vector2D& a, const Vector2D& b) -> double;
};
