#ifndef UTMATRIX_H_INCLUDED
#define UTMATRIX_H_INCLUDED

#include "Matrix.h"

TEST (Matrix, Constructor){
    double a[3]={0,2,2}, b[3]={2,2,6};
    Vector v(a, 3),w(b, 3);
    Vector * vec[3] = {0,&v, &w};
    Matrix m(vec,3);

    ASSERT_EQ(0,m[1][1]);
    ASSERT_EQ(2,m[2][2]);
    m[1][1] = 100;
    ASSERT_EQ(100, m[1][1]);
    //swapVector(m,1,2);
    //ASSERT_EQ(2,m[1]->component(2));
    //ASSERT_EQ(0,m[2]->component(1));
}

TEST (Matrix, Assignment){
    double a[3]={0,2,2}, b[3]={2,2,6};
    Vector v(a, 3),w(b, 3);
    Vector * vec[3] = {0,&v, &w};
    Matrix m(vec, 3);
    Matrix n(vec, 3);

    ASSERT_EQ(0,m[1][1]);
    ASSERT_EQ(2,m[2][2]);
    m[1][1] = 100;
    ASSERT_EQ(100, m[1][1]);
    n = m;
    ASSERT_EQ(100, n[1][1]);
    n = n;
    ASSERT_EQ(100, n[1][1]);
}


#endif // UTMATRIX_H_INCLUDED
