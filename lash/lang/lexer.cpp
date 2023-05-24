#include <vector>
#include <string>

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
}

vector<Token *>
lex(string &toParse, int N)
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
            continue;
        }
    }

    return ret;
}