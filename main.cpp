#include <iostream>

#include "libs/googletest/googlemock/include/gmock/gmock.h"
#include "libs/googletest/googletest/include/gtest/gtest.h"

#include "Geometry.h"
#include "Matrix.h"

TEST(TestAngle, CreateAngles) {
    const Angle a;
    const Angle b(3.141592);
    Angle c(b);
    ASSERT_EQ(a.getRadian(), 0);
    ASSERT_EQ(b.getRadian(), 3.141592);
    ASSERT_EQ(c.getRadian(), 3.141592);
}

TEST(TestAngle, AnglesBinOperators) {
    const Angle a(3.141592 / 3);
    const Angle b(3.141592);

    Angle c = b + a;
    ASSERT_EQ(c.getRadian(), b.getRadian() + a.getRadian());

    c = b - a;
    ASSERT_EQ(c.getRadian(), b.getRadian() - a.getRadian());

    c = b / a;
    ASSERT_EQ(c.getRadian(), b.getRadian() / a.getRadian());

    c = b / 2;
    ASSERT_EQ(c.getRadian(), b.getRadian() / 2);

    c = b / 1.2;
    ASSERT_EQ(c.getRadian(), b.getRadian() / 1.2);

    c = b / 0.5;
    ASSERT_EQ(c.getRadian(), b.getRadian() / 0.5);

    c = b * 2;
    ASSERT_EQ(c.getRadian(), b.getRadian() * 2);

    c = b * 1.2;
    ASSERT_EQ(c.getRadian(), b.getRadian() * 1.2);

    c = b * 0.5;
    ASSERT_EQ(c.getRadian(), b.getRadian() * 0.5);
}

TEST(TestAngle, AngleUnOperators) {
    Angle a(3.141592 / 4);
    Angle b(3.141592);
    Angle c(a);

    a += b;
    ASSERT_EQ(a.getRadian(), b.getRadian()*(1+0.25));
    ASSERT_EQ(b.getRadian(), 3.141592);
    a = c;

    a -= b;
    ASSERT_EQ(a.getRadian(), b.getRadian()*(0.25-1));
    ASSERT_EQ(b.getRadian(), 3.141592);
}

TEST(TestVector, Operators) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D d(Point2D(10, 10), Point2D(5, 7));
    Vector2D e(4, 3);

    Vector2D c = a + b;
    ASSERT_DOUBLE_EQ(c.getVectorX(), 5);
    ASSERT_DOUBLE_EQ(c.getVectorY(), 3);

    c = a + d;
    ASSERT_DOUBLE_EQ(c.getVectorX(), -3);
    ASSERT_DOUBLE_EQ(c.getVectorY(), -1);

    c = e * 2;
    ASSERT_EQ(c.getLength(), 10);
    ASSERT_DOUBLE_EQ(c.getVectorX(), 8);
    ASSERT_DOUBLE_EQ(c.getVectorY(), 6);
}

TEST(TestVector, VectorsOperators) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D d(Point2D(10, 10), Point2D(5, 7));
    Vector2D e(-5, -3);
    Vector2D f(0, 0);

    double z = a * b;
    ASSERT_DOUBLE_EQ(z, 8);

    z = d * b;
    ASSERT_DOUBLE_EQ(z, -18);

    z = f * d;
    ASSERT_DOUBLE_EQ(z, 0);

    z = b ^ a;
    ASSERT_DOUBLE_EQ(z, 4);

    z = a ^ b;
    ASSERT_DOUBLE_EQ(z, -4);

    z = a ^ a;
    ASSERT_DOUBLE_EQ(z, 0);

    z = a ^ f;
    ASSERT_DOUBLE_EQ(z, 0);

    z = a ^ e;
    ASSERT_DOUBLE_EQ(z, 4);

    z = e ^ a;
    ASSERT_DOUBLE_EQ(z, -4);

    z = b ^ e;
    ASSERT_DOUBLE_EQ(z, -4);

    z = e ^ b;
    ASSERT_DOUBLE_EQ(z, 4);
}

TEST(TestMatrix, MatrixSize) {
    std::vector<double> z;
    z.push_back(11);
    z.push_back(-3);
    z.push_back(-15);
    z.push_back(-2);

    Matrix a(z);
    z.push_back(0);
    Matrix b(z);

    z.clear();

    ASSERT_DOUBLE_EQ(a.size(), 4);
    ASSERT_DOUBLE_EQ(b.size(), 9);

    ASSERT_DOUBLE_EQ(a.at(0, 1), -15);
    ASSERT_DOUBLE_EQ(a.at(0, 2), Matrix::INF);
    ASSERT_DOUBLE_EQ(a.at(-1, -1), 1);
}

TEST(TestSubSystem, DetMartix2x2) {
    std::vector<double> z;
    z.push_back(11);
    z.push_back(-3);
    z.push_back(-15);
    z.push_back(-2);
    Matrix m(z);

    z.clear();
    z.push_back(5);
    z.push_back(7);
    z.push_back(-4);
    z.push_back(1);
    Matrix s(z);

    z.clear();
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    Matrix e(z);

    ASSERT_DOUBLE_EQ(m.det(), -67);
    ASSERT_DOUBLE_EQ(s.det(), 33);
    ASSERT_DOUBLE_EQ(e.det(), 0);
}

TEST(TestMatrix, DetMatrix) {
    std::vector<double> z;
    z.push_back(1);
    z.push_back(-2);
    z.push_back(3);
    z.push_back(4);
    z.push_back(0);
    z.push_back(6);
    z.push_back(-7);
    z.push_back(8);
    z.push_back(9);
    Matrix a(z);
    z.clear();

    z.push_back(5);
    z.push_back(3);
    z.push_back(1);
    z.push_back(4);
    z.push_back(-7);
    z.push_back(5);
    z.push_back(0);
    z.push_back(2);
    z.push_back(9);
    Matrix b(z);
    z.clear();

    z.push_back(5);
    z.push_back(3);
    z.push_back(1);
    z.push_back(4);
    z.push_back(-7);
    z.push_back(5);
    z.push_back(0);
    z.push_back(2);
    z.push_back(0.5);
    Matrix c(z);

    z.clear();

    ASSERT_DOUBLE_EQ(a.det(), 204);
    ASSERT_DOUBLE_EQ(b.det(), -465);
    ASSERT_DOUBLE_EQ(c.det(), -65.5);
}

TEST(TestMatrix, DetBigMatrix) {
    std::vector<double> z;
    z.push_back(5);
    z.push_back(3);
    z.push_back(1);
    z.push_back(4);
    z.push_back(-7);
    z.push_back(5);
    z.push_back(0);
    z.push_back(2);
    z.push_back(9);
    z.push_back(5);
    z.push_back(44);
    z.push_back(1);
    z.push_back(8);
    z.push_back(99);
    z.push_back(-53);
    z.push_back(0.5);
    Matrix d(z);
    z.clear();

    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);
    z.push_back(0);

    Matrix e(z);
    z.clear();

    ASSERT_DOUBLE_EQ(d.size(), 16);
    ASSERT_DOUBLE_EQ(d.det(), -181359);
    ASSERT_DOUBLE_EQ(e.det(), 0);
}

TEST(TestGeometry, PointOnLine) {
    Point2D a(-1, 5);
    Point2D b(-2, 10);
    Point2D c(3, 3);
    Point2D d(0,0);
    Point2D e(-100000, 500000);
    Point2D f(-9999999, -9999999);

    ASSERT_TRUE(Geometry::onOneLine(a, b, e));
    ASSERT_TRUE(Geometry::onOneLine(c, d, f));
    ASSERT_TRUE(Geometry::onOneLine(d, d, d));
    ASSERT_TRUE(Geometry::onOneLine(a, a, a));
    ASSERT_FALSE(Geometry::onOneLine(a, b, f));
    ASSERT_FALSE(Geometry::onOneLine(a, b, c));
    ASSERT_FALSE(Geometry::onOneLine(f, a, d));
}

int main() {
    // Test Angle
    ::testing::InitGoogleTest();

    // std::cout << q;

    return RUN_ALL_TESTS();
    // return 0;
}
