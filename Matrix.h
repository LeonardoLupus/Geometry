//
// Created by leonid on 14.03.24.
//

#pragma once

#include <vector>
#include <concepts>

class Matrix {
public:
    static constexpr double INF = 1.7976931348623158e+308;
    Matrix();
    explicit Matrix(const std::vector<double> &m, unsigned int column = 0, unsigned int line = 0);
    ~Matrix();

    [[nodiscard]] auto size() const -> unsigned long int;

    template <std::integral Type>
    [[nodiscard]] auto at(Type x, Type y) -> double;

    [[nodiscard]] auto isEmpty() const -> bool;

    [[nodiscard]] auto det() const -> double;
private:
    auto swapLine(int i, int j)->void;

    template <std::integral Type>
    auto ch(Type x, Type y, double number)->void;

    std::vector<double> matrix;
    unsigned int column;
    unsigned int line;
};

template<std::integral Type>
auto Matrix::at(Type x, Type y) -> double {
    if (x == -1 && y == -1) {return 1;}
    if (x > column-1 || y > line-1 || x < 0 || y < 0) {return INF;}
    return matrix[x + y*column];
}

template<std::integral Type>
auto Matrix::ch(Type x, Type y, double number) -> void {
    matrix[x + y*column] = number;
}
