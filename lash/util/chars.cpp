#include <vector>


bool char_in_set(char c, std::vector<char> chars){
    for (std::size_t i = 0; i < chars.size(); i++) {
      if (c == chars.at(i)){
        return true;
      }
    }
    return false;
}

bool is_numeric(char c)
{
  return char_in_set(c, std::vector<char>({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}));
};
