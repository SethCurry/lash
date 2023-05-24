#include "lash/lang/lexer.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(LexerTest, IsSeparator)
{
    EXPECT_TRUE(is_separator('('));
}
