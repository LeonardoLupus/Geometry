//
// Created by leonid on 22.02.24.
//

#include "Angel.h"

#include <cmath>

auto operator+(const Angel& aAngel, const Angel& bAngel) -> Angel {
    return Angel(aAngel.angel + bAngel.angel);
}

auto operator-(const Angel& aAngel, const Angel& bAngel) -> Angel {
    return Angel(aAngel.angel - bAngel.angel);
}

auto operator/(const Angel &aAngel, const Angel &bAngel) -> double {
    return aAngel.angel / bAngel.angel;
}

auto operator/(const Angel &aAngel, const double num) -> Angel {
    return Angel(aAngel.angel / num);
}

Angel operator*(const Angel &aAngel, const double num) {
    return Angel(aAngel.angel * num);
}

auto Angel::operator+=(const Angel& bAngel) -> Angel& {
    angel = angel + bAngel.angel;
    return *this;
}

auto Angel::operator-=(const Angel& bAngel) -> Angel& {
    angel = angel - bAngel.angel;
    return *this;
}

auto Angel::operator=(const Angel &addAngel) -> Angel& {
    angel = addAngel.angel;
    return *this;
}

auto Angel::operator=(const double addAngel) -> Angel & {
    angel = addAngel;
    return *this;
}

Angel::Angel() {
    angel = 0;
}

Angel::Angel(const Angel &copy) {
    angel = copy.angel;
}

Angel::Angel(const double radians) {
    angel = radians;
    angelAdjustment();
}

auto Angel::setDegree(const double degree) -> void {
    angel = PI * degree / 180;
    angelAdjustment();
}

auto Angel::setRadian(const double radians) -> void {
    angel = radians;
    angelAdjustment();
}

auto Angel::getDegree() const -> const double {
    return angel * 180 / PI;
}

auto Angel::getRadian() const -> const double {
    return angel;
}

auto Angel::getBisectorDegree() const -> const double {
    return getDegree()/2;
}

auto Angel::getBisectorRadians() const -> const double {
    return getRadian()/2;
}

auto Angel::angelAdjustment() -> void {
    if (angel > 2*PI || angel < 2*PI) {
        angel = std::fmod(angel, 2*PI);
    }
}