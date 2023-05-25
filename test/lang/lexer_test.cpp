#include "lash/lang/lexer.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

// Demonstrate some basic assertions.
TEST(LexerTest, IsSeparator)
{
    EXPECT_TRUE(is_separator('('));
};

TEST(LexerTest, ReadUntilCharsTest)
{
    char *const test_string = (char *)"this is a test";
    std::string as_string = std::string(test_string);
    std::vector<char> break_on_chars = {' '};
    int break_at = read_len_until_chars(as_string, 15, 0, break_on_chars);
    EXPECT_EQ(break_at, 4);
}

TEST(LexerTest, ReadStringLiteralTest)
{
    char *const test_string = (char *)"this is \"a test\" string";
    std::string as_string = std::string(test_string);
    int literal_len = read_string_literal_len(as_string, 17, 8);
    EXPECT_EQ(literal_len, 8);
    EXPECT_STREQ(as_string.substr(8, literal_len).c_str(), (char *)"\"a test\"");
}

TEST(LexerTest, LexTest)
{
    char *const test_string = (char *)"(\"a literal\")";
    std::string as_string = std::string(test_string);
    std::vector<Token *> lexed = lex(as_string, 14);
    EXPECT_EQ(3, lexed.size()) << "Incorrect number of tokens returned by lexer";

    Token first_entry = *lexed.at(0);
    char *open_paren = (char *)"(";
    EXPECT_EQ(token_t::separator, first_entry.type);
    EXPECT_STREQ(open_paren, first_entry.value.c_str());

    Token second_entry = *lexed.at(1);
    char *lit = (char *)"\"a literal\"";
    EXPECT_EQ(token_t::literal, second_entry.type);
    EXPECT_STREQ(lit, second_entry.value.c_str()) << "Literal does not match expected contents";

    Token third_entry = *lexed.at(2);
    char *close_paren = (char *)")";
    EXPECT_EQ(token_t::separator, third_entry.type);
    EXPECT_STREQ(close_paren, third_entry.value.c_str());
}

TEST(LexerTest, IsNumeric)
{
    EXPECT_TRUE(is_numeric('1'));
    EXPECT_FALSE(is_numeric('a'));
}

TEST(LexerTest, ReadNumLiteralLen)
{
    char *const test_string = (char *)"(12345)";
    std::string as_string = std::string(test_string);

    int l = read_num_literal_len(as_string, 8, 1);
    EXPECT_EQ(l, 5);
}

TEST(LexerTest, Lex_Number)
{
    char *const test_string = (char *)"(12345)";
    std::string as_string = std::string(test_string);
    std::vector<Token *> lexed = lex(as_string, 7);

    Token first_entry = *lexed.at(0);
    char *open_paren = (char *)"(";
    EXPECT_EQ(token_t::separator, first_entry.type);
    EXPECT_STREQ(open_paren, first_entry.value.c_str());

    Token second_entry = *lexed.at(1);
    char *num = (char *)"12345";
    EXPECT_EQ(token_t::literal, second_entry.type);
    EXPECT_STREQ(num, second_entry.value.c_str());

    Token third_entry = *lexed.at(2);
    char *close_paren = (char *)")";
    EXPECT_EQ(token_t::separator, third_entry.type);
    EXPECT_STREQ(close_paren, third_entry.value.c_str());
}