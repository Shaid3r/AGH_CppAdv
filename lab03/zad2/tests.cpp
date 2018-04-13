#include <gtest/gtest.h>
#include <exception>

std::string fizzBuzz(unsigned int x) {
    std::string result = std::to_string(x);
    if (x == 0)
        throw std::runtime_error("0 is not valid input");
    
    if (x % 15 == 0)
        result = "FizzBuzz";
    else if (x % 3 == 0)
        result = "Fizz";
    else if (x % 5 == 0)
        result = "Buzz";
    
    return result;
}

// PART A
// --------------------------------------------------------------
// TEST(fizzBuzzTest, default) {
//     ASSERT_EQ("1", fizzBuzz(1));
//     ASSERT_EQ("2", fizzBuzz(2));
// }

// TEST(fizzBuzzTest, exceptionIfZero) {
//     ASSERT_THROW(fizzBuzz(0), std::runtime_error);
// }

// TEST(fizzBuzzTest, 3divider) {
//     ASSERT_EQ("Fizz", fizzBuzz(3));
//     ASSERT_EQ("Fizz", fizzBuzz(6));
//     ASSERT_EQ("Fizz", fizzBuzz(9));
// }

// TEST(fizzBuzzTest, 5divider) {
//     ASSERT_EQ("Buzz", fizzBuzz(5));
//     ASSERT_EQ("Buzz", fizzBuzz(10));
//     ASSERT_EQ("Buzz", fizzBuzz(50));
// }

// TEST(fizzBuzzTest, 3and5divider) {
//     ASSERT_EQ("FizzBuzz", fizzBuzz(15));
//     ASSERT_EQ("FizzBuzz", fizzBuzz(150));
//     ASSERT_EQ("FizzBuzz", fizzBuzz(300));
// }

// PART B
// --------------------------------------------------------------
using param = std::tuple<std::string, int>;
struct FizzBuzzTestSuite : public ::testing::TestWithParam<param> {
	std::string expectedResult = std::get<0>(GetParam());
	int argument = std::get<1>(GetParam());
};

TEST_P(FizzBuzzTestSuite, shouldReturnDefaultValue) {
    ASSERT_EQ(fizzBuzz(argument), expectedResult);
}

const std::vector<param> defaultValues {
    std::make_tuple("1", 1),
    std::make_tuple("2", 2)
};

INSTANTIATE_TEST_CASE_P(tests, FizzBuzzTestSuite,
                         testing::ValuesIn(defaultValues));

struct FizzCase_FizzBuzzTestSuite : public FizzBuzzTestSuite {};

TEST_P(FizzCase_FizzBuzzTestSuite, 3divider) {
    ASSERT_EQ(fizzBuzz(argument), expectedResult);
}

const std::vector<param> fizzValues {
    std::make_tuple("Fizz", 3),
    std::make_tuple("Fizz", 6),
    std::make_tuple("Fizz", 9)
};

INSTANTIATE_TEST_CASE_P(tests, FizzCase_FizzBuzzTestSuite,
                         testing::ValuesIn(fizzValues));

struct BuzzCase_FizzBuzzTestSuite : public FizzBuzzTestSuite {};

TEST_P(BuzzCase_FizzBuzzTestSuite, 5divider) {
    ASSERT_EQ(fizzBuzz(argument), expectedResult);
}

const std::vector<param> buzzValues {
    std::make_tuple("Buzz", 5),
    std::make_tuple("Buzz", 10),
    std::make_tuple("Buzz", 20)
};

INSTANTIATE_TEST_CASE_P(tests, BuzzCase_FizzBuzzTestSuite,
                         testing::ValuesIn(buzzValues));


struct FizzBuzzCase_FizzBuzzTestSuite : public FizzBuzzTestSuite {};

TEST_P(FizzBuzzCase_FizzBuzzTestSuite, 3and5divider) {
    ASSERT_EQ(fizzBuzz(argument), expectedResult);
}

const std::vector<param> fizzBuzzValues {
    std::make_tuple("FizzBuzz", 15),
    std::make_tuple("FizzBuzz", 30),
    std::make_tuple("FizzBuzz", 300)
};

INSTANTIATE_TEST_CASE_P(tests, FizzBuzzCase_FizzBuzzTestSuite,
                         testing::ValuesIn(fizzBuzzValues));
