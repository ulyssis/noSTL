#include <gtest/gtest.h>
#include "../lib/SimpleVector.h"
// #include "SimpleVectorImpl.h"
#include "../lib/ErrorCode.h"

// Test case for SimpleVector_double
class SimpleVectorTest_double : public ::testing::Test
{
protected:
    SimpleVector<double> vec;

    // You can do set-up work for each test here.
    void SetUp() override
    {
        // Initialize SimpleVector with some values if needed
        vec.push_back(1.1);
        vec.push_back(2.2);
    }

    // You can do clean-up work that doesn't throw exceptions here.
    void TearDown() override
    {
        // Clean up code if necessary
    }
};

// Tests that the SimpleVector can add elements.
TEST_F(SimpleVectorTest_double, HandlesSizeIncrease)
{
    vec.push_back(3.3);
    ASSERT_EQ(3, vec.size());
}

// Test case for SimpleVector_int
class SimpleVectorTest_int : public ::testing::Test
{
protected:
    SimpleVector<int> vec;

    // You can do set-up work for each test here.
    void SetUp() override
    {
        // Initialize SimpleVector with some values if needed
        vec.push_back(1);
        vec.push_back(2);
    }

    // You can do clean-up work that doesn't throw exceptions here.
    void TearDown() override
    {
        // Clean up code if necessary
    }
};

// Tests that the SimpleVector can add elements.
TEST_F(SimpleVectorTest_int, HandlesSizeIncrease)
{
    vec.push_back(3);
    ASSERT_EQ(3, vec.size()); // Check size is as expected
}

// Tests that the SimpleVector throws when popping from empty.
TEST_F(SimpleVectorTest_int, HandlesPopFromEmpty)
{
    SimpleVector<int> emptyVec;
    ASSERT_EQ(static_cast<int>(ErrorCode::OutOfRange), emptyVec.pop_back()); // Should return OutOfRange
}

// Tests that the SimpleVector pops correctly.
TEST_F(SimpleVectorTest_int, HandlesPopBack)
{
    int value = vec.pop_back();
    ASSERT_EQ(2, value);      // Check popped value is correct
    ASSERT_EQ(1, vec.size()); // Ensure size is decremented
}

// Test empty vector
TEST_F(SimpleVectorTest_int, HandlesEmptyVector)
{
    SimpleVector<int> emptyVec;
    ASSERT_TRUE(emptyVec.is_empty());
    ASSERT_EQ(0, emptyVec.size());
    ASSERT_EQ(0, emptyVec.get_capacity());
}
