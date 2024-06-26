//
// Created by leonid on 22.02.24.
//

#include "Angle.h"

#include <cmath>

auto operator+(const Angle& aAngle, const Angle& bAngle) -> Angle {
    return Angle(aAngle.angle + bAngle.angle);
}

auto operator-(const Angle& aAngle, const Angle& bAngle) -> Angle {
    return Angle(aAngle.angle - bAngle.angle);
}

auto operator/(const Angle &aAngle, const Angle &bAngle) -> double {
    return aAngle.angle / bAngle.angle;
}

auto operator/(const Angle &aAngle, const double num) -> Angle {
    return Angle(aAngle.angle / num);
}

Angle operator*(const Angle &aAngle, const double num) {
    return Angle(aAngle.angle * num);
}

auto Angle::operator+=(const Angle& bAngle) -> Angle& {
    angle = angle + bAngle.angle;
    return *this;
}

auto Angle::operator-=(const Angle& bAngle) -> Angle& {
    angle = angle - bAngle.angle;
    return *this;
}

auto Angle::operator=(const Angle &addAngle) -> Angle& = default;

auto Angle::operator=(const double addAngle) -> Angle & {
    angle = addAngle;
    return *this;
}

Angle::Angle() {
    angle = 0;
}

Angle::Angle(const Angle &copy) {
    angle = copy.angle;
    AngleAdjustment();
}

Angle::Angle(const double radians) {
    angle = radians;
    AngleAdjustment();
}

auto Angle::setDegree(const double degree) -> void {
    angle = PI * degree / 180;
    AngleAdjustment();
}

auto Angle::setRadian(const double radians) -> void {
    angle = radians;
    AngleAdjustment();
}

auto Angle::getDegree() const -> double {
    return angle * 180 / PI;
}

auto Angle::getRadian() const -> double {
    return angle;
}

auto Angle::getBisectorDegree() const -> double {
    return getDegree()/2;
}

auto Angle::getBisectorRadians() const -> double {
    return getRadian()/2;
}

auto Angle::AngleAdjustment() -> void {
//    if (angle > PI || angle < -PI) {
//        angle = std::fmod(angle, PI);
//    }
    if(angle > 2*PI || angle < -2*PI) { angle = std::fmod(angle, 2*PI);}
    if(angle > PI) {angle= angle - 2*PI;}
    else if(angle < -PI) {angle += 2*PI;}
}


