//
// Created by bsi on 22.01.23.
//

#ifndef COUNTER_TEST_CPP
#define COUNTER_TEST_CPP

#include <gtest/gtest.h>
#include "../include/counter_model.h"


/**
* @class CounterModelTest
* @brief Test fixture for CounterConsoleModel
* This class is a test fixture for the CounterConsoleModel class. It is derived from the gtest testing framework's
* TestWithParam class, allowing it to accept a parameterized test input for each test case.
* The fixture contains an instance of the CounterConsoleModel class, which is used in the test cases.
*/
class CounterModelTest : public ::testing::TestWithParam<std::tuple<std::string, char, int>> {
protected:
/**
* @brief instance of the CounterConsoleModel class to be used in the test cases
*/
CounterConsoleModel model;
};
/**
* @brief Test case for counting characters in a string
* This test case uses the GetParam() function provided by the gtest testing framework to retrieve the tuple of
* input parameters for the test case. It then calls the count_char() function of the CounterConsoleModel instance
* and compares the returned value to the expected count.
*/
TEST_P(CounterModelTest, CountChar) {
auto [str, ch, expected_count] = GetParam();
auto count = model.count_char(str, ch);
EXPECT_EQ(count, expected_count);
}

INSTANTIATE_TEST_SUITE_P(CounterModelTestCases, CounterModelTest, ::testing::Values(
        std::make_tuple("III", 'I', 3),
        std::make_tuple("I", 'I', 1),
        std::make_tuple(";@!`", 'I', 0),
        std::make_tuple("س", '0', 0),
        std::make_tuple("", '2', 0),
        std::make_tuple("ajdshkfak", ' ', 0),
        std::make_tuple("IIII", '\0', 0),
        std::make_tuple("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaIIsadad", 'I', 2)
));

#endif //COUNTER_TEST_CPP
