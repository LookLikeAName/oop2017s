#include <gtest/gtest.h>
//#include <iostream>

//using namespace std;
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

    ASSERT_EQ(3 ,innerProduct(4, a, b));
}
