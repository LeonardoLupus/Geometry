//
// Created by leonid on 14.03.24.
//
#pragma once

#include "Vector2D.h"

#include <vector>
#include <list>

class Geometry {
public:
    static auto onOneLine(const Point2D& a, const Point2D& b, const Point2D& c) -> const bool;
};
