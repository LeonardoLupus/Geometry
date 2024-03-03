#include <iostream>

#include "Vector2D.h"

int main() {
    // Test Angel
    std::cout << "Test Angel.h" << std::endl << std::endl;
    Angel alph;
    Angel beth(0.523599);

    Vector2D a(1, 1);
    Vector2D b(2, 0);
    a = a * 6;
    double s = b^a;

    alph = Vector2D::angelVectors(a, b);

    std::cout << "Alpth = " << b.getVectorX() << ";" << b.getVectorY() << " " << alph.getDegree() << std::endl;

    return 0;
}
