#include <iostream>

#include "libs/googletest/googlemock/include/gmock/gmock.h"
#include "libs/googletest/googletest/include/gtest/gtest.h"

#include "Vector2D.h"

TEST(TestAngle, CreateAngles) {
    Angle a;
    Angle b(3.141592);
    Angle c(b);
    ASSERT_EQ(a.getRadian(), 0);
    ASSERT_EQ(b.getRadian(), 3.141592);
    ASSERT_EQ(c.getRadian(), 3.141592);
}

TEST(TestAngle, AnglesBinOperators) {
    Angle a(3.141592 / 3);
    Angle b(3.141592);
    Angle c;

    c = b + a;
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
    a = c;
}

TEST(TestVector, Operators) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D d(Point2D(10, 10), Point2D(5, 7));
    Vector2D e(4, 3);
    Vector2D f(0, 0);
    Vector2D c(0,0);
    double z = 0;

    c = a + b;
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
    Vector2D g(-4, 2);
    Vector2D c(0,0);
    double z = 0;

    z = a * b;
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

int main() {
    // Test Angle
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
