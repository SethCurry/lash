#ifndef _LEXER_
#define _LEXER_

#include <string>
#include <vector>

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
    std::string value;
    Token(token_t tType, std::string tValue)
    {
        type = tType;
        value = tValue;
    }
};

bool is_separator(char c);
std::vector<Token *> lex(std::string const &toParse, int const N);

bool is_numeric(char c)
{
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    }
    return false;
}

int read_len_until_chars(std::string const &toParse, int const N, int const start_at, std::vector<char> const break_list)
{
    int len = 1;
    for (int i = start_at + 1; i < N; i++)
    {
        char l = toParse.at(i);
        for (std::size_t j = 0; j < break_list.size(); j++)
            if (l == break_list.at(j))
            {
                return len;
            }
        len += 1;
    }

    return -1;
};

int read_string_literal_len(std::string const &toParse, int const N, int const start_at)
{
    std::vector<char> break_chars = {'"'};
    int ret = read_len_until_chars(toParse, N, start_at, break_chars);
    if (ret != -1)
    {
        return ret + 1;
    }
    return ret;
}

int read_num_literal_len(std::string const &toParse, int const N, int const start_at)
{
    std::vector<char> break_chars = {'(', ')', ' ', '\n'};
    int ret = read_len_until_chars(toParse, N, start_at, break_chars);
    return ret;
}

#endif