#include "lash/lang/parser.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(ParserTest, Instantiate)
{
    char *s = (char *)"test string";
    Statement st = Statement(std::vector<std::variant<Value, Statement>>({Value(type_t::number, s, 12)}));
}
