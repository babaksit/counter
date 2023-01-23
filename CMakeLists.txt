cmake_minimum_required(VERSION 3.10)
project(counter)

set(CMAKE_CXX_STANDARD 17)

# Add the source files
set(SOURCES
        src/counter_model.cpp
        src/counter_view.cpp
        src/counter_controller.cpp
        src/input_validator.cpp
        src/input_reader.cpp
        main.cpp
        )

set(TEST_SOURCES
        src/counter_model.cpp
)
# Add the tests files
set(TESTS
        tests/counter_model_test.cpp
        )

# Add the Google Test library
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the executable
add_executable(counter ${SOURCES})

# Create the tests executable
add_executable(counter_test ${TESTS} ${TEST_SOURCES})
target_link_libraries(counter_test ${GTEST_BOTH_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(counter_test)