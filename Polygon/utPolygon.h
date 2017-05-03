#ifndef UTPOLYGON_H_INCLUDED
#define UTPOLYGON_H_INCLUDED

#include "../inClass1/Vector.h"
#include "Polygon.h"
#include <cmath>

TEST(CreatePolygon, order1) {
    double a[2] = {1,0}, b[2] = {1,1}, c[2] = {0, 0};
    Vector u(a, 2), v(b, 2), w(c, 2);
    // hmmm... maybe we need to fix Matrix
    Vector *p[3] = { &u, &v, &w};
    Polygon triangle(p, 3);

    ASSERT_EQ(u, triangle.vertex(1));
    ASSERT_EQ(v, triangle.vertex(2));
    ASSERT_EQ(w, triangle.vertex(3));
}

TEST(CreatePolygon, perimeter) {
    double a[2] = {1,0}, b[2] = {1,1}, c[2] = {0, 0};
    Vector u(a, 2), v(b, 2), w(c, 2);
    Vector *p[3] = { &u, &v, &w};
    Polygon triangle(p, 3);

    ASSERT_EQ(1+1+sqrt(2), triangle.perimeter());
}



#endif // UTPOLYGON_H_INCLUDED
