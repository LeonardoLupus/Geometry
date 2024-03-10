//
// Created by leonid on 22.02.24.
//

#ifndef ANGLE_H
#define ANGLE_H

constexpr double PI = 3.14159265359;

class Angle {
public:
    Angle();
    Angle(const Angle& copy);
    // Поумолчанию углы задаются в радианах
    explicit Angle(double radians);

    friend auto operator+(const Angle& aAngle, const Angle& bAngle)-> Angle;
    friend auto operator-(const Angle& aAngle, const Angle& bAngle)-> Angle;
    friend auto operator/(const Angle& aAngle, const Angle& bAngle)-> double;
    friend auto operator/(const Angle& aAngle, double num)-> Angle;
    friend auto operator*(const Angle& aAngle, double num)-> Angle;
    auto operator+=(const Angle& bAngle)->Angle&;
    auto operator-=(const Angle& bAngle)->Angle&;
    auto operator=(const Angle& addAngle)->Angle&;
    auto operator=(double addAngle)->Angle&;

    auto setDegree(double degree) -> void;
    auto setRadian(double radians) -> void;

    auto getDegree() const -> const double;
    auto getRadian() const -> const double;
    auto getBisectorDegree() const -> const double;
    auto getBisectorRadians() const -> const double;

private:
    double angle;

    auto AngleAdjustment() -> void;
};

#endif //ANGLE_h
