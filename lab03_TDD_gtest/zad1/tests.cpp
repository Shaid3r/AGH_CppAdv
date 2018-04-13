#include <gtest/gtest.h>
#include <exception>

int fib(int n) {
    if (n < 0) throw std::runtime_error("You must pass non negative value!");
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

TEST(FIB, Zero) {
    ASSERT_EQ(0, fib(0));
}

TEST(FIB, One) {
    ASSERT_EQ(1, fib(1));
}

TEST(FIB, N) {
    ASSERT_EQ(1, fib(2));
    ASSERT_EQ(2, fib(3));
    ASSERT_EQ(55, fib(10));
}

TEST(FIB, Negative) {
    ASSERT_THROW(fib(-1), std::runtime_error);
}