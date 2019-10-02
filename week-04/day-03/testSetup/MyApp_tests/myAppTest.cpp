#include <iostream>
#include <gtest/gtest.h>
#include "apples.h"

TEST(apple_check, test_apple)
{
    std::cout << "Starting test apples()" << std::endl;
    EXPECT_EQ(getApple(), "apple");
}

TEST(SumCheck, testSumFullList)
{
    std::cout << "Starting test sum() with full list" << std::endl;
    vector<int> toSum = {2,4,6,1,32,5,6,3,2};
    ASSERT_EQ(sum(toSum), 61);
}

TEST(SumCheck, testSum0Elements)
{
    std::cout << "Starting test sum() with 0 elements" << std::endl;
    vector<int> toSum = {};
    ASSERT_EQ(sum(toSum), 0);
}

TEST(SumCheck, testSumOneElement)
{
    std::cout << "Starting test sum() with 1 element" << std::endl;
    vector<int> toSum = {2};
    ASSERT_EQ(sum(toSum), 2);
}

TEST(SumCheck, testSumNegativeElement)
{
    std::cout << "Starting test sum() with negative elements" << std::endl;
    vector<int> toSum = {-2, -4, -120};
    ASSERT_EQ(sum(toSum), -126);
}

TEST(AnagramCheck, testAnagram)
{
    std::cout << "Starting anagram check" << std::endl;
    ASSERT_EQ(anagram("asddsaasd", "aaasssddd"), true);
}

TEST(CountLetters, testCountLetters )
{
    std::cout << "Starting letter count check" << std::endl;
    map<char, int> test = countLetters("kecskesajt");
    ASSERT_EQ(test['t'], 1);
}


TEST(Fibonacci, testFibonacci)
{
    std::cout << "fibonacci check" << std::endl;
    std::cout << fibonacci(10) << std::endl;
    ASSERT_EQ(fibonacci(10), 89);
}

TEST(Fibonacci, testFibonacciNegativeInput)
{
    std::cout << "Starting fibonacci check with negative input" << std::endl;
    ASSERT_EQ(fibonacci(-3), -1);
}

