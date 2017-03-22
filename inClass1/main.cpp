#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "Vector.h"
using namespace std;
int X(int num1, int num2);
/*
int main()
{
    int input1, input2, output;
    cin >> input1 >> input2;
    cout << X(input1, input2) << endl;
    return 0;
}
*/
int X(int num1, int num2)
{
    return num1 * num2;
}



int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}

TEST (testX,first) {
    ASSERT_TRUE(X(2, 3) ==6);
}

TEST (testX, second) {
    ASSERT_EQ(20, X(4,5));
}

int innerProduct(int dim,int a[], int b[]) {
    int result= 0;
    for(int x=0;x<dim;x++){
        result+=a[x]*b[x];
    }
    return result;
}

int innerProduct(int d1,int d2, int a[], int b[]) {
    int result= 0;
    if(d1!=d2){
        throw string("wrong dim");
    }
    for(int x=0;x<d1;x++){
        result+=a[x]*b[x];
    }
    return result;
}

TEST (testInnerProduct, Normal) {
    int a[2] = {0, 1}, b[2] = {1, 1};

    ASSERT_EQ(1 ,innerProduct(2, a, b));
}

TEST (testInnerProduct, Normal1) {
    int a[3] = {0, 1, 1}, b[3] = {1, 1, 1};
    ASSERT_EQ(2 ,innerProduct(3, a, b));
}

TEST (testInnerProduct, Normal2) {
    int a[4] = {0, 1, 1, 1}, b[4] = {1, 1, 1, 1};

    ASSERT_EQ(3 ,innerProduct(4 , a, b));
}

TEST (testInnerProduct, Abnormal1) {
    int a[3] = {0, 1, 1}, b[4] = {1, 1, 1, 1};

    try {
        // if this fails, innerProduct is not doing its job
        innerProduct(3 ,4, a, b);
        FAIL()<<"Should not be here!";
    } catch(string s) {
        // if this fails, innerProduct does not throw the expected exception
        ASSERT_EQ(string("wrong dim"),s);
    }
}

TEST (Vector, create)
{
    double a[2]={1,2};
    Vector v(a, 2);

    ASSERT_EQ(2,v.dim());
    ASSERT_EQ(1,v.component(1));
    ASSERT_EQ(2,v.component(2));
}

TEST (Vector, innerProduct){
    double a[2]={1,2}, b[2]={3,4};
    Vector v(a, 2),w(b, 2);

    ASSERT_EQ(11 ,innerProduct(v,w));
    // testing if a correct copy constructor is provided
    EXPECT_EQ(1,v.component(1));
    EXPECT_EQ(2,v.component(2));
}

TEST (Vector, innerProductEx){
    double a[2]={1,2}, b[3]={3,4,5};
    Vector v(a, 2),w(b, 3);
    ASSERT_ANY_THROW(innerProduct(v,w));
}

TEST (Vector, innerProductExString){
    double a[2]={1,2}, b[3]={3,4,5};
    Vector v(a, 2),w(b, 3);
    try {
        innerProduct(v,w);
        FAIL() << "should not be here!";
    } catch(string s) {
        ASSERT_EQ(string("wrong dim"), s);
    }
}

int foo(int i, int j) {
    return ++i+j++ -1;
}

TEST (foo, first) {
    int x =2, y =3;
    ASSERT_EQ(5,foo(x,y));
    ASSERT_EQ(2,x);
    ASSERT_EQ(3,y);
}

//call by reference

void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
TEST (swap, first) {
    int i=3,j=4;
    swap(i,j);
    ASSERT_EQ(4,i);
    ASSERT_EQ(3,j);
}

TEST (Vector, multiply) {
    double a[3]={0,2,2}, b[3]={2,2,6};
    Vector v(a, 3),w(b, 3);
    multiply(0.5,v);
    ASSERT_EQ(0,v.component(1));
    ASSERT_EQ(1,v.component(2));
    ASSERT_EQ(1,v.component(3));
}
TEST (Vector, linearTransform){
    double a[3]={1,1,3}, b[3]={0,1,1};
    Vector v(a, 3),w(b, 3);
    linearTransform(-1,w,v);
    ASSERT_EQ(1,v.component(1));
    ASSERT_EQ(0,v.component(2));
    ASSERT_EQ(2,v.component(3));
}
#include <vector>
TEST (Matrix, First){
    double a[3]={0,2,2}, b[3]={2,2,6};
    Vector v(a, 3),w(b, 3);
    std::vector <Vector*> m;
    m.push_back(0);
    m.push_back(&v);
    m.push_back(&w);
    ASSERT_EQ(0,m[1]->component(1));
    ASSERT_EQ(2,m[2]->component(2));
    swapVector(m,1,2);
    ASSERT_EQ(2,m[1]->component(2));
    ASSERT_EQ(0,m[2]->component(1));
}

TEST (vector, intArray) {
    int a[5] = {1,2,3,4,5};
    std::vector<int> v(a,a+5);
    ASSERT_EQ(a[3],v[3]);
    v.push_back(6);
    ASSERT_EQ(6,v[5]);
    ASSERT_EQ(6,v.size());

}
