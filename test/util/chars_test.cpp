#include <gtest/gtest.h>
#include "lash/util/chars.hpp"


TEST(CharsTest, IsNumeric)
{
    EXPECT_TRUE(is_numeric('1'));
    EXPECT_FALSE(is_numeric('a'));
}
