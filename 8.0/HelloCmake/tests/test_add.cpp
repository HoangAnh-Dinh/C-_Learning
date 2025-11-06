#include "gtest/gtest.h"
#include "mylib.h"

TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 20), 30);
}

TEST(AddTest, HandlesNegativeInput) {
    EXPECT_EQ(add(-1, -1), -2);
    EXPECT_EQ(add(-5, 5), 0);
}