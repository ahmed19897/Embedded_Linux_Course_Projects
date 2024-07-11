#include "mockcalc.h"
#include <gtest/gtest.h>
#include "gmock/gmock.h"

using namespace ::testing;

TEST(calculatormocksuite, global_function_add)
{
    calculatormock calc;

    EXPECT_CALL(calc,add(5,3))
        .WillOnce(Return(8));

    ASSERT_EQ(8, calc.add(5,3));
}

TEST(calculator, global_function_sub)
{
        calculatormock calc;

    EXPECT_CALL(calc,sub(5,3))
        .WillOnce(Return(2));


    ASSERT_EQ(2, calc.sub(5,3));
}

TEST(calculator, global_function_mul)
{
        calculatormock calc;

    EXPECT_CALL(calc,mul(5,3))
        .WillOnce(Return(15));


    ASSERT_EQ(15, calc.mul(5,3));
}

TEST(calculator, global_function_div)
{
        calculatormock calc;

    EXPECT_CALL(calc,div(6,3))
        .WillOnce(Return(2));


    ASSERT_EQ(2, calc.div(6,3));
}