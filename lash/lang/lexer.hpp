#ifndef _LEXER_
#define _LEXER_

#include <string>
#include <vector>

enum token_t
{
    symbol = 1,
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

    std::string stringify()
    {
        int type_value = static_cast<int>(type);
        std::string type_string = std::to_string(type_value);
        return "<Token type=" + type_string + " value=\"" + value + "\">";
    }
};

bool is_separator(char c);
std::vector<Token *> lex(std::string const &toParse, int const N);

bool is_numeric(char c);

int read_len_until_chars(std::string const &toParse, int const N, int const start_at, std::vector<char> const break_list);

int read_string_literal_len(std::string const &toParse, int const N, int const start_at);

int read_num_literal_len(std::string const &toParse, int const N, int const start_at);

int read_symbol(std::string const &toParse, int const N, int const start_at);

#endif