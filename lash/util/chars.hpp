#ifndef _UTIL_CHARS_
#define _UTIL_CHARS_

#include <vector>

// returns whether the given character is a number (i.e. 0-9)
bool is_numeric(char c);

// returns whether the given character is inside the provided vector of characters
bool char_in_set(char c, std::vector<char> chars);

#endif