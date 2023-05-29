#include <stdexcept>
#include <string>
#include "parser.hpp"
#include "lash/lang/lexer.hpp"

int find_statement_len(std::vector<Token *> tokens, int start){
  Token start_token = *tokens.at(start);
  if (start_token.type != token_t::separator || start_token.value != std::string({'('})) {
    throw std::logic_error("statement does not start with (");
  }
  // number of open parantheses, so we can balance them with closed ones
  int open_parens = 0;
  for (std::size_t i = start; i < tokens.size(); i++)
  {
    Token t = *tokens.at(i);

    if (t.type == token_t::separator) {
      if (t.value == std::string({'('})){
        open_parens += 1;
      }
      if (t.value == std::string({')'})){
        open_parens -= 1;
      }
    }

    if (open_parens == 0) {
      return i-start+1;
    }
  }

  return -1;
}
