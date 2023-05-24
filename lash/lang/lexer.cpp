#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum token_t
{
    identifier = 1,
    separator = 2,
    literal = 3,
    comment = 4,
};

class Token
{
public:
    token_t type;
    string value;
    Token(token_t tType, string tValue)
    {
        type = tType;
        value = tValue;
    }
};

bool is_separator(char c)
{
    switch (c)
    {
    case '(':
    case ')':
        return true;
    }

    return false;
};

int read_until_chars(string const &toParse, int const N, int const start_at, vector<char> const break_list)
{
    for (int i = start_at; i < N; i++)
    {
        char l = toParse.at(i);
        for (int j = 0; j < break_list.size(); j++)
            if (l == break_list.at(j))
            {
                return i;
            }
    }

    return -1;
};

vector<Token *>
lex(string const &toParse, int N)
{
    vector<Token *> ret;

    bool in_literal = false;
    bool in_identifier = false;

    for (int i = 0; i < N; i++)
    {
        char l = toParse[i];
        if (is_separator(l))
        {
            Token *t = new Token(token_t::separator, string(&l));
            ret.push_back(t);
            in_literal = false;
            in_identifier = false;
            continue;
        }
    }

    return ret;
}