#include <gtest/gtest.h>

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}

TEST (test1,first) {
    ASSERT_FALSE(false);
}

TEST (test1, second) {
    ASSERT_TRUE(true);
}

TEST (test1, third) {
    EXPECT_TRUE(false);
    EXPECT_FALSE(true);
}

TEST (test1, fourth) {
    ASSERT_TRUE(false);
    EXPECT_FALSE(true);
}

TEST (test2, first) {
    ASSERT_EQ(1,1);
}

TEST (test2, second) {
    ASSERT_EQ(1.1,1.1);
}

#include <string>
TEST (test2, third) {
    std::string s("hello");
    ASSERT_EQ(std::string("hello"),s);
}

