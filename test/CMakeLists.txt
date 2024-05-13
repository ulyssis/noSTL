# /test/CMakeLists.txt

# Include GoogleTest so it can be used for testing
include(FetchContent)
FetchContent_MakeAvailable(googletest)

# Add the executable that will run the tests
add_executable(${PROJECT_NAME}_tests SimpleVector_test.cpp)

# Link the executable with GoogleTest and the library being tested
target_link_libraries(${PROJECT_NAME}_tests GTest::gtest_main simpleVector)

# Let CMake know this executable is meant for testing
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
