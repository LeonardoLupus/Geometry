//
// Created by leonid on 22.02.24.
//

#ifndef ANGLE_H
#define ANGLE_H

constexpr double PI = 3.1415926535897932384626433832795;

class Angle {
public:
    Angle();
    Angle(const Angle& copy);
    // Поумолчанию углы задаются в радианах
    explicit Angle(double radians);

    friend auto operator+(const Angle& aAngle, const Angle& bAngle)-> Angle;
    friend auto operator-(const Angle& aAngle, const Angle& bAngle)-> Angle;
    friend auto operator/(const Angle& aAngle, const Angle& bAngle)-> double;
    friend auto operator<=>(const Angle& aAngel, const Angle& bAngel)-> bool = default;
    friend auto operator/(const Angle& aAngle, double num)-> Angle;
    friend auto operator*(const Angle& aAngle, double num)-> Angle;
    auto operator+=(const Angle& bAngle)->Angle&;
    auto operator-=(const Angle& bAngle)->Angle&;
    auto operator=(const Angle& addAngle)->Angle&;
    auto operator=(double addAngle)->Angle&;

    auto setDegree(double degree) -> void;
    auto setRadian(double radians) -> void;

    [[nodiscard]] auto getDegree() const -> double;
    [[nodiscard]] auto getRadian() const -> double;
    [[nodiscard]] auto getBisectorDegree() const -> double;
    [[nodiscard]] auto getBisectorRadians() const -> double;

private:
    double angle;

    auto AngleAdjustment() -> void;
};

#endif //ANGLE_h
