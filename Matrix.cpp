//
// Created by leonid on 14.03.24.
//

#include "Matrix.h"

#include <cmath>

template<typename Type>
bool isNumberAPerfectSqare(Type number) {
    return number == pow(floor(sqrt(number)), 2);
}

void makeSqareMatrix(std::vector<double> &mtr) {
    const auto d = ceil(sqrt(static_cast<double>(mtr.size())));
    const auto size = mtr.size();
    for (int i = 0; i < pow(d, 2) - static_cast<double>(size); ++i) {
        mtr.push_back(0);
    }
}

Matrix::Matrix() {
    column = 0;
    line = 0;
    matrix.clear();
}

Matrix::Matrix(const std::vector<double> &m, unsigned int column, unsigned int line) {
    for (auto element: m) {
        matrix.push_back(element);
    }
    if (column == 0 || line == 0) {
        makeSqareMatrix(matrix);
        this->column = static_cast<unsigned int> (sqrt(static_cast<double>(size())));
        this->line = this->column;
    } else {
        this->column = column;
        this->line = line;
    }
}

Matrix::~Matrix() {
    matrix.clear();
}

auto Matrix::size() const -> unsigned long int {
    return matrix.size();
}

auto Matrix::isEmpty() const -> bool {
    return matrix.empty();
}

auto Matrix::det() const -> double {
    Matrix copy(matrix);
    if (copy.column != copy.line) {return INF;}
    int sign = 1;
    for (size_t k = 0; k < copy.column-1; ++k) {
        if(copy.at(k,k) == 0) {
            bool isDiagonalZero = true;
            for (size_t m = k + 1; m < copy.column; ++m) {
                if(copy.at(m, k) != 0) {
                    sign*=-1;
                    copy.swapLine(static_cast<int>(m), static_cast<int>(k));
                    isDiagonalZero = false;
                    break;
                }
            }
            if(isDiagonalZero) {return 0;}
        }

        for (size_t i = k+1; i < copy.column; ++i) {
            for (size_t j = k+1; j < copy.column; ++j) {
                const double m = (copy.at(i, j)*copy.at(k, k) - copy.at(i, k)*copy.at(k, j))/copy.at(k-1, k-1);
                copy.ch(i,j,m);
            }
        }
    }
    return copy.at(copy.column-1, copy.line-1) * sign;
}

auto Matrix::swapLine(const int i, const int j)->void {
    for (size_t k = 0; k <= column; ++k) {
        std::swap(matrix[k+j*column], matrix[k+i*column]);
    }
}

