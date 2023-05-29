#ifndef _PARSER_
#define _PARSER_

#include <variant>
#include <vector>
#include "lash/lang/lexer.hpp"

enum type_t
{
    string = 1,
    number = 2,
};

class Value
{
public:
    int size;
    type_t type;
    void *ptr;

    Value(type_t t, void *loc, int s)
    {
        size = s;
        type = t;
        ptr = loc;
    }
};

class Statement
{
public:
    std::vector<std::variant<Value, Statement>> children;

    Statement(std::vector<std::variant<Value, Statement>> c)
    {
        children = c;
    }
};

int find_statement_len(std::vector<Token *> tokens, int start);

#endif