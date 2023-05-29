#include "lash/lang/parser.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(FindStatementLen, invalid_no_end_paren)
{
    std::vector<Token *> tokens = {new Token(token_t::separator, std::string({'('}))};
    int s_len = find_statement_len(tokens, 0);
    EXPECT_EQ(-1, s_len);
}

TEST(FindStatementLen, nested_statements)
{
    char *const test_string = (char *)"(do-fn \"first arg\" (a-child-arg))";
    std::string as_string = std::string(test_string);
    std::vector<Token *> lexed = lex(as_string, 34);

    int s_len = find_statement_len(lexed, 0);
    EXPECT_EQ(7, s_len);
}