#ifndef UTPOLYGON_H_INCLUDED
#define UTPOLYGON_H_INCLUDED

#include "../inClass1/Vector.h"
#include "Polygon.h"
#include <cmath>
using namespace std;

TEST(Polygon, construct) {
    double a[2] = {1,0}, b[2] = {1,1}, c[2] = {0, 0};
    Vector u(a, 2), v(b, 2), w(c, 2);
    // hmmm... maybe we need to fix Matrix
    Vector *p[3] = { &u, &v, &w};
    Polygon triangle(p, 3);

    ASSERT_EQ(u, triangle.vertex(1));
    ASSERT_EQ(v, triangle.vertex(2));
    ASSERT_EQ(w, triangle.vertex(3));
}

TEST(Polygon, perimeter) {
    double a[2] = {1,0}, b[2] = {1,1}, c[2] = {0, 0};
    Vector u(a, 2), v(b, 2), w(c, 2);
    Vector *p[3] = { &u, &v, &w};
    Polygon triangle(p, 3);

    ASSERT_EQ(1+1+sqrt(2), triangle.perimeter());
}

TEST(Polygon,area){
 double a[2] = {1,0}, b[2] = {1,1}, c[2] = {0, 0};
    Vector u(a, 2), v(b, 2), w(c, 2);
    Vector *p[3] = { &u, &v, &w};
    Polygon triangle(p, 3);

    ASSERT_EQ(1.0/2.0,triangle.area());
}
TEST(Polygon,areaSquare){
    double a[2] = {1, 0}, b[2] = {1, 1}, c[2] = {0, 1},d[2] = {0, 0};
    Vector u(a, 2), v(b, 2), w(c, 2), x(d, 2);
    Vector *p[4] = { &u, &v, &w, &x};
    Polygon square(p, 4);

    EXPECT_NEAR( 1.0, square.area(), 0.00001);
}

TEST(Polygon, Order){
    double a[2] = {1, 1}, b[2] = {0, 2}, c[2] = {0, 0},d[2] = {1, 0};
    Vector u(a, 2), v(b, 2), w(c, 2), x(d, 2);
    Vector *p[4] = { &u, &v, &w, &x};
    Polygon square(p, 4);

    EXPECT_NEAR( 1.5, square.area(), 0.00001);
}

TEST(Polygon, notOrder){
    double a[2] = {1, 1}, b[2] = {0, 2}, c[2] = {0, 0},d[2] = {1, 0};
    Vector u(b, 2), v(a, 2), w(c, 2), x(d, 2);
    Vector *p[4] = { &u, &v, &w, &x};
    Polygon square2(p, 4);

    EXPECT_NEAR( 1.5, square2.area(), 0.00001);
}
#include <algorithm>
bool decreasing (int i,int j) { return (i>j); }
bool increasing (int i,int j) { return (i<j); }
TEST(sort, decreasing){
    int a[]={4, 2, 3};
    vector<int> v(a,a+3);
    sort (v.begin(), v.end(), decreasing);
    EXPECT_EQ( 4, v[0]);
    EXPECT_EQ( 3, v[1]);
    EXPECT_EQ( 2, v[2]);
}

TEST(sort, increasing){
    int a[]={4, 2, 3};
    vector<int> v(a,a+3);
    sort (v.begin(), v.end(), increasing);
    EXPECT_EQ( 2, v[0]);
    EXPECT_EQ( 3, v[1]);
    EXPECT_EQ( 4, v[2]);
}

bool increasingByDistanceTo3(int i, int j) {
    return abs(i-3) < abs(j-3);
}
TEST(sort, increasingByDistanceTo3){
    int a[]={4, 1, 3};
    vector<int> v(a,a+3);
    sort (v.begin(), v.end(), increasingByDistanceTo3);
    EXPECT_EQ( 3, v[0]);
    EXPECT_EQ( 4, v[1]);
    EXPECT_EQ( 1, v[2]);
}

class increasingByDistanceToN {
public:
    increasingByDistanceToN(int N):n(N){}
    bool operator() (int i, int j) {
        return abs(i-n) < abs(j-n);
    }
private:
    int n;
};

TEST(sort, increasingByDistanceToN){
    int a[]={4, 1, 3};
    vector<int> v(a,a+3);
    sort (v.begin(), v.end(), increasingByDistanceToN(3));
    EXPECT_EQ( 3, v[0]);
    EXPECT_EQ( 4, v[1]);
    EXPECT_EQ( 1, v[2]);
}

TEST(sort, increasingByDistanceTo10){
    int a[]={4, 1, 3};
    vector<int> v(a,a+3);
    sort (v.begin(), v.end(), increasingByDistanceToN(10));
    EXPECT_EQ( 4, v[0]);
    EXPECT_EQ( 3, v[1]);
    EXPECT_EQ( 1, v[2]);
}

#endif // UTPOLYGON_H_INCLUDED
