#include "lash/lang/lexer.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

// Demonstrate some basic assertions.
TEST(LexerTest, IsSeparator)
{
    EXPECT_TRUE(is_separator('('));
};

TEST(LexerTest, ReadUntilChars)
{
    char *const test_string = "this is a test";
    std::string as_string = std::string(test_string);
    std::vector<char> break_on_chars = {' '};
    int break_at = read_until_chars(as_string, 15, 0, break_on_chars);
    EXPECT_EQ(break_at, 4);
}