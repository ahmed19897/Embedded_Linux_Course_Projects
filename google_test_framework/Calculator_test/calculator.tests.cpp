#include "calculator.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(calculator, global_function_add)
{
    calculator calc;
    ASSERT_EQ(8, calc.add(5,3));
}

TEST(calculator, global_function_sub)
{
    calculator calc;
    ASSERT_EQ(2, calc.sub(5,3));
}

TEST(calculator, global_function_mul)
{
    calculator calc;
    ASSERT_EQ(15, calc.mul(5,3));
}

TEST(calculator, global_function_div)
{
    calculator calc;
    ASSERT_EQ(2, calc.div(6,3));
}