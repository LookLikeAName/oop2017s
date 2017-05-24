#ifndef UTSHAPE_H_INCLUDED
#define UTSHAPE_H_INCLUDED
#include "../Polygon/Polygon.h"
#include "Shape.h"
TEST(shape, printPolygon)
{
    double a[2] = {1, 1}, b[2] = {0, 1}, c[2] = {0, 0},d[2] = {1, 0};
    Vector u(a, 2), v(b, 2), w(c, 2), x(d, 2);
    Vector *p[4] = { &u, &v, &w, &x};
    Polygon square = createConvexPolygon(p, 4);
    ASSERT_EQ("name:polygon, area= 1, perimeter= 4", printShape(square));
}

TEST(shape, printCircle)
{
    double a[2]={0,0};
    Vector c(a,2);
    Circle cir(c, 1);
    ASSERT_EQ("name:circle, area= 3.14159, perimeter= 6.28318", printShape(cir));
}
#endif // UTSHAPE_H_INCLUDED
