//
// Created by leonid on 22.02.24.
//

#ifndef ANGEL_H
#define ANGEL_H

constexpr double PI = 3.14159265359;

class Angel {
public:
    Angel();
    Angel(const Angel& copy);
    // Поумолчанию углы задаются в радианах
    explicit Angel(double radians);

    friend auto operator+(const Angel& aAngel, const Angel& bAngel)-> Angel;
    friend auto operator-(const Angel& aAngel, const Angel& bAngel)-> Angel;
    friend auto operator/(const Angel& aAngel, const Angel& bAngel)-> double;
    friend auto operator/(const Angel& aAngel, double num)-> Angel;
    friend auto operator*(const Angel& aAngel, double num)-> Angel;
    auto operator+=(const Angel& bAngel)->Angel&;
    auto operator-=(const Angel& bAngel)->Angel&;
    auto operator=(const Angel& addAngel)->Angel&;
    auto operator=(double addAngel)->Angel&;

    auto setDegree(double degree) -> void;
    auto setRadian(double radians) -> void;

    auto getDegree() const -> const double;
    auto getRadian() const -> const double;
    auto getBisectorDegree() const -> const double;
    auto getBisectorRadians() const -> const double;

private:
    double angel;

    auto angelAdjustment() -> void;
};

#endif //ANGEL_H
