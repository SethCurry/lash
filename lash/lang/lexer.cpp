#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "spdlog/spdlog.h"
#include "lexer.hpp"

using namespace std;

vector<char> const separators = {'(', ')'};

bool is_separator(char c)
{
    for (std::size_t i = 0; i < separators.size(); i++)
    {
        if (c == separators.at(i))
        {
            return true;
        }
    }

    return false;
};

std::vector<Token *>
lex(std::string const &toParse, int N)
{
    vector<Token *> ret;
    int lineNo = 0;
    int charNo = 0;

    for (int i = 0; i < N; i++)
    {
        char l = toParse[i];
        if (l == '\n')
        {
            lineNo += 1;
            charNo = 1;
            continue;
        }
        else
        {
            charNo += 1;
        }
        if (l == ' ')
        {
            continue;
        }

        if (is_separator(l))
        {
            Token *t = new Token(token_t::separator, string(1, l));
            ret.push_back(t);
            continue;
        }

        if (is_numeric(l))
        {
            int num_len = read_num_literal_len(toParse, N, i);
            if (num_len == -1)
            {
                num_len = N;
            }
            string lit = toParse.substr(i, num_len);
            Token *t = new Token(token_t::literal, lit);
            ret.push_back(t);
            i = i + num_len - 1;
            continue;
        }

        if (l == '"')
        {
            int literal_len = read_string_literal_len(toParse, N, i);
            if (literal_len == -1)
            {
                throw std::logic_error("string missing \" terminator");
            }
            string lit = toParse.substr(i, literal_len);
            Token *t = new Token(token_t::literal, lit);
            ret.push_back(t);
            i = i + literal_len - 1;
            continue;
        }

        // TODO should be probably be an "is_valid_symbol_char" kind of call
        // but this technically works. Until it doesn't, anyways.
        if (i >= N - 1)
        {
            break;
        }
        int symbol_len = read_symbol(toParse, N, i);
        if (symbol_len == -1)
        {
            symbol_len = N;
        }
        string sym = toParse.substr(i, symbol_len);
        Token *t = new Token(token_t::symbol, sym);
        ret.push_back(t);
        i = i + symbol_len - 1;
        continue;
    }

    return ret;
}