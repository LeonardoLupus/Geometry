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
    const Angle a(PI / 3);
    const Angle b(PI);

    Angle c = b + a;
    Angle d(-PI+a.getRadian());
    ASSERT_DOUBLE_EQ(c.getRadian(), d.getRadian());

    c = b - a;
    ASSERT_DOUBLE_EQ(c.getRadian(), b.getRadian() - a.getRadian());

    c = b / a;
    ASSERT_DOUBLE_EQ(c.getRadian(), b.getRadian() / a.getRadian());

    c = b / 2;
    ASSERT_DOUBLE_EQ(c.getRadian(), b.getRadian() / 2);

    c = b / 1.2;
    ASSERT_DOUBLE_EQ(c.getRadian(), b.getRadian() / 1.2);

    c = b / 0.5;
    ASSERT_DOUBLE_EQ(c.getRadian(), std::fmod(b.getRadian() / 0.5, PI));

    c = b * 2;
    ASSERT_DOUBLE_EQ(c.getRadian(), std::fmod(b.getRadian() * 2, PI));

    c = b * 1.2;
    ASSERT_DOUBLE_EQ(c.getRadian(), (b.getRadian() * 1.2 - 2*PI));

    c = b * 0.5;
    ASSERT_DOUBLE_EQ(c.getRadian(), b.getRadian() * 0.5);
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

TEST(TestVector, CreateVector) {
    Vector2D a;
    Vector2D b(Point2D(1, 1));
    Vector2D c(Point2D(1, 1), Point2D(4, 4));
    Vector2D d(Angle(PI/2), 5);
    Vector2D e(Angle(PI), 1, Point2D(1, 1));

    ASSERT_DOUBLE_EQ(a.getX(), 0);
    ASSERT_DOUBLE_EQ(a.getY(), 0);
    ASSERT_DOUBLE_EQ(a.getStart().getX(), 0);
    ASSERT_DOUBLE_EQ(a.getStart().getY(), 0);

    ASSERT_DOUBLE_EQ(b.getX(), 1);
    ASSERT_DOUBLE_EQ(b.getY(), 1);
    ASSERT_DOUBLE_EQ(b.getStart().getX(), 0);
    ASSERT_DOUBLE_EQ(b.getStart().getY(), 0);

    ASSERT_DOUBLE_EQ(c.getX(), 3);
    ASSERT_DOUBLE_EQ(c.getY(), 3);
    ASSERT_DOUBLE_EQ(c.getStart().getX(), 1);
    ASSERT_DOUBLE_EQ(c.getStart().getY(), 1);

    ASSERT_DOUBLE_EQ(d.getX(), 0);
    ASSERT_DOUBLE_EQ(d.getY(), 5);
    ASSERT_DOUBLE_EQ(d.getStart().getX(), 0);
    ASSERT_DOUBLE_EQ(d.getStart().getY(), 0);

    ASSERT_DOUBLE_EQ(e.getX(), 0);
    ASSERT_DOUBLE_EQ(e.getY(), 1);
    ASSERT_DOUBLE_EQ(e.getStart().getX(), 1);
    ASSERT_DOUBLE_EQ(e.getStart().getY(), 1);
}

TEST(TestVector, Operators) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D d(Point2D(10, 10), Point2D(5, 7));
    Vector2D e(4, 3);

    Vector2D c = a + b;
    ASSERT_DOUBLE_EQ(c.getX(), 5);
    ASSERT_DOUBLE_EQ(c.getY(), 3);

    c = a + d;
    ASSERT_DOUBLE_EQ(c.getX(), -3);
    ASSERT_DOUBLE_EQ(c.getY(), -1);

    c = e * 2;
    ASSERT_EQ(c.getRadius(), 10);
    ASSERT_DOUBLE_EQ(c.getX(), 8);
    ASSERT_DOUBLE_EQ(c.getY(), 6);

}

TEST(TestVector, VectorsOperators) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D d(Point2D(10, 10), Point2D(5, 7));
    Vector2D e(-5, -3);
    Vector2D f(0, 0);
    Vector2D g(5, 0);
    Vector2D h(Point2D(3, 1), Point2D(0,0));

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

    ASSERT_DOUBLE_EQ(~f, 0);
    ASSERT_DOUBLE_EQ(~g, 5);
    ASSERT_DOUBLE_EQ(~a, sqrt(2)*2);

    ASSERT_DOUBLE_EQ((-a).getX(), -2);
    ASSERT_DOUBLE_EQ((-a).getY(), -2);
    ASSERT_DOUBLE_EQ((-b).getX(), h.getX());
    ASSERT_DOUBLE_EQ((-b).getY(), h.getY());
}

TEST(TestVector, AngelBTWVector) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D c(Point2D(-5, 0), Point2D(0, 5));
    Vector2D d(Point2D(2, 3), Point2D(5, 4));
    Vector2D e(4, 0);

    ASSERT_TRUE(Vector2D::isCollinear(a, a));
    ASSERT_TRUE(Vector2D::isCollinear(a, c));
    ASSERT_TRUE(Vector2D::isCollinear(b, d));
    ASSERT_FALSE(Vector2D::isCollinear(a, b));
    ASSERT_FALSE(Vector2D::isCollinear(a,  d));

    ASSERT_DOUBLE_EQ(Vector2D::angleBTWVectors(a, c).getDegree(), 0);
    ASSERT_DOUBLE_EQ(Vector2D::angleBTWVectors(a, e).getDegree(), -45);
    ASSERT_DOUBLE_EQ(Vector2D::angleBTWVectors(a, -a).getDegree(), 180);
    ASSERT_DOUBLE_EQ(Vector2D::angleBTWVectors(e, -e).getDegree(), 180);
}

TEST(TestVector, NormalVector) {
    Vector2D a(3, 1);
    Vector2D b(-3, 2);
//    Vector2D c(Point2D(-5, 0), Point2D(0, 5));

    ASSERT_DOUBLE_EQ(a.getNormal().getX(), 1);
    ASSERT_DOUBLE_EQ(a.getNormal().getY(), -3);
    ASSERT_DOUBLE_EQ(b.getNormal().getX(), 2);
    ASSERT_DOUBLE_EQ(b.getNormal().getY(), 3);
    ASSERT_DOUBLE_EQ(a.getNormalUnit().getRadius(), 1);
}

TEST(TestVector, Transfer) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D c;

    c = a.parallelTransfer(2*std::sqrt(2));
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getX()), 4);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getY()), 0);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getX()), 2);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getY()), -2);

    c = a.parallelTransfer(-2*std::sqrt(2));
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getX()), 0);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getY()), 4);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getX()), -2);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getY()), 2);

    c = a.transfer(b);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getX()), 5);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getY()), 3);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getX()), 3);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getY()), 1);

    c = a.transfer(-b);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getX()), -1);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getEnd().getY()), 1);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getX()), -3);
    ASSERT_DOUBLE_EQ(Point2D::roundPr(c.getStart().getY()), -1);

}

TEST(TestVector, distanceVector) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D c(Point2D(-5, 0), Point2D(0, 5));
    Point2D p(0, 2);
    Point2D q(3, -1);
    Point2D w(3, 5);
    Point2D s(0, 0);

    ASSERT_DOUBLE_EQ(Vector2D::distancePointToLine(p, a), std::sqrt(2));
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToLine(q, a), 2*std::sqrt(2));
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToLine(w, a), std::sqrt(2));
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToLine(p, -a), std::sqrt(2));

    ASSERT_DOUBLE_EQ(Vector2D::distancePointToSegment(p, a), std::sqrt(2));
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToSegment(w, b), 4);
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToSegment(p, -a), std::sqrt(2));
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToSegment(w, -b), 4);
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToSegment(s, a), 0);
    ASSERT_DOUBLE_EQ(Vector2D::distancePointToSegment(s, c), 5*std::sqrt(2)/2);
}

TEST(TestVector, intersectVector) {
    Vector2D a(2, 2);
    Vector2D b(3, 1);
    Vector2D c(Point2D(4, 0), Point2D(1, 3));
    Vector2D d(Point2D(-2, -1), Point2D(2, 3));
    Vector2D e(Point2D(1, 4), Point2D(5, 4));
    Vector2D f(Point2D(3 ,5), Point2D(5, 2));

    ASSERT_TRUE(Vector2D::isIntersectionLines(a, b));
    ASSERT_TRUE(Vector2D::isIntersectionLines(e, f));
    ASSERT_TRUE(Vector2D::isIntersectionLines(b, c));
    ASSERT_FALSE(Vector2D::isIntersectionLines(a, d));

    ASSERT_TRUE(Vector2D::isIntersectionSegments(a, b));
    ASSERT_TRUE(Vector2D::isIntersectionSegments(a, c));
    ASSERT_TRUE(Vector2D::isIntersectionSegments(c, d));
    ASSERT_FALSE(Vector2D::isIntersectionSegments(a, e));
    ASSERT_FALSE(Vector2D::isIntersectionSegments(d, b));

    ASSERT_DOUBLE_EQ(Vector2D::intersectionSegmentsPoint(a, c).getX(), 2);
    ASSERT_DOUBLE_EQ(Vector2D::intersectionSegmentsPoint(a, c).getY(), 2);
    ASSERT_DOUBLE_EQ(Vector2D::intersectionSegmentsPoint(b, c).getX(), 3);
    ASSERT_DOUBLE_EQ(Vector2D::intersectionSegmentsPoint(b, c).getY(), 1);
    ASSERT_DOUBLE_EQ(Vector2D::intersectionSegmentsPoint(d, c).getX(), 1.5);
    ASSERT_DOUBLE_EQ(Vector2D::intersectionSegmentsPoint(d, c).getY(), 2.5);

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

TEST(TestGeometry, sidePoint) {
    Vector2D a(Point2D(0, 0), Point2D(5, 5));
    Point2D b(6, 6);
    Point2D c(0, 0);
    Point2D d(3, 1);
    Point2D e(1, 100);
    Point2D f(-4, -5);
    Point2D g(-2, 2);

    ASSERT_FALSE(Geometry::isPointRigthOfVector(b, a));
    ASSERT_FALSE(Geometry::isPointRigthOfVector(c, a));
    ASSERT_TRUE(Geometry::isPointRigthOfVector(d, a));
    ASSERT_FALSE(Geometry::isPointRigthOfVector(e, a));
    ASSERT_TRUE(Geometry::isPointRigthOfVector(f, a));
    ASSERT_FALSE(Geometry::isPointRigthOfVector(g, a));
}

TEST(Geometry, AreaTriangle) {
    Point2D a(0, 0);
    Point2D b(3, 0);
    Point2D c(0, 4);
    Point2D d(5, 2);
    Point2D e(-3, -2);
    Point2D f(8, 0);

    ASSERT_DOUBLE_EQ(Geometry::areaOfTriangle(a, b, c), 6);
    ASSERT_DOUBLE_EQ(Geometry::areaOfTriangle(a, d, c), 10);
    ASSERT_DOUBLE_EQ(Geometry::areaOfTriangle(a, e, c), 6);
    ASSERT_DOUBLE_EQ(Geometry::areaOfTriangle(a, b, f), 0);
}

int f(const int& p) {
    return p;
}

int main() {
    // Test Angle
//    ::testing::InitGoogleTest();

    // std::cout << q;
    int i = 0;
    auto z = f(5);

//    return RUN_ALL_TESTS();
    // return 0;
}
