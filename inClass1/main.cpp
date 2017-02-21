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
    ASSERT_TRUE(X(2, 3) == 5);
}

TEST (testX, second) {
    ASSERT_EQ(20, X(4,5));
}
