#pragma once
#include "pch.h"
#include"Rational.h"
#include<iostream>
TEST(Addition, TestName)
{
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational result = r1 + r2;

    EXPECT_EQ(result.get_numerator(), 5);
    EXPECT_EQ(result.get_denominator(), 6);
}

TEST(Subtraction, TestName)
{
    Rational r1(3, 4);
    Rational r2(1, 4);
    Rational result = r1 - r2;

    EXPECT_EQ(result.get_numerator(), 1);
    EXPECT_EQ(result.get_denominator(), 2);
}

TEST(Multiplication, TestName)
{
    Rational r1(2, 3);
    Rational r2(3, 4);
    Rational result = r1 * r2;

    EXPECT_EQ(result.get_numerator(), 1);
    EXPECT_EQ(result.get_denominator(), 2);
}

TEST(Division, TestName)
{
    Rational r1(3, 5);
    Rational r2(2, 3);
    Rational result = r1 / r2;

    EXPECT_EQ(result.get_numerator(), 9);
    EXPECT_EQ(result.get_denominator(), 10);
}

TEST(Equality, TestName)
{
    Rational r1(2, 3);
    Rational r2(4, 6);

    EXPECT_TRUE(r1 == r2);
}

TEST(Inequality, TestName)
{
    Rational r1(3, 5);
    Rational r2(2, 3);

    EXPECT_TRUE(r1 != r2);
}

TEST(GreaterThan, TestName)
{
    Rational r1(3, 4);
    Rational r2(1, 2);

    EXPECT_TRUE(r1 > r2);
}

TEST(LessThan, TestName)
{
    Rational r1(1, 3);
    Rational r2(1, 2);

    EXPECT_TRUE(r1 < r2);
}

TEST(GreaterThanOrEqual, TestName)
{
    Rational r1(3, 4);
    Rational r2(3, 4);
    Rational r3(1, 2);

    EXPECT_TRUE(r1 >= r2);
    EXPECT_TRUE(r1 >= r3);
}

TEST(LessThanOrEqual, TestName)
{
    Rational r1(1, 2);
    Rational r2(1, 2);
    Rational r3(3, 4);

    EXPECT_TRUE(r1 <= r2);
    EXPECT_TRUE(r1 <= r3);
}

TEST(Increment, TestName)
{
    Rational r(1, 2);
    ++r;

    EXPECT_EQ(r.get_numerator(), 3);
    EXPECT_EQ(r.get_denominator(), 2);
}

TEST(Decrement, TestName)
{
    Rational r(3, 2);
    --r;

    EXPECT_EQ(r.get_numerator(), 1);
    EXPECT_EQ(r.get_denominator(), 2);
}

TEST(UnaryNegation, TestName)
{
    Rational r(2, 3);
    -r;

    EXPECT_EQ(r.get_numerator(), -2);
    EXPECT_EQ(r.get_denominator(), 3);
}

TEST(UnaryPlus, TestName)
{
    Rational r(2, 3);
    +r;

    EXPECT_EQ(r.get_numerator(), 2);
    EXPECT_EQ(r.get_denominator(), 3);
}

TEST(LogicalNot, TestName)
{
    Rational r(0, 2);

    EXPECT_TRUE(!r);
}

TEST(Assignment, TestName)
{
    Rational r1(1, 2);
    Rational r2(3, 4);
    r1 = r2;

    EXPECT_TRUE(r1 == r2);
}

TEST(CompoundAddition, TestName)
{
    Rational r1(1, 3);
    Rational r2(1, 4);
    r1 += r2;

    EXPECT_EQ(r1.get_numerator(), 7);
    EXPECT_EQ(r1.get_denominator(), 12);
}

TEST(CompoundSubtraction, TestName)
{
    Rational r1(3, 5);
    Rational r2(2, 5);
    r1 -= r2;

    EXPECT_EQ(r1.get_numerator(), 1);
    EXPECT_EQ(r1.get_denominator(), 5);
}

TEST(CompoundMultiplication, TestName)
{
    Rational r1(2, 3);
    Rational r2(3, 4);
    r1 *= r2;

    EXPECT_EQ(r1.get_numerator(), 1);
    EXPECT_EQ(r1.get_denominator(), 2);
}

TEST(CompoundDivision, TestName)
{
    Rational r1(3, 5);
    Rational r2(2, 3);
    r1 /= r2;

    EXPECT_EQ(r1.get_numerator(), 9);
    EXPECT_EQ(r1.get_denominator(), 10);
}