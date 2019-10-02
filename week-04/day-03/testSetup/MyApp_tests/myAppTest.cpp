#include <iostream>
#include <gtest/gtest.h>
#include "apples.h"

TEST(apple_check, test_apple)
{
    EXPECT_EQ(getApple(), "apple");
}