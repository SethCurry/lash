#include <string>
#include <vector>

bool is_separator(char c);
int read_until_chars(std::string const &toParse, int const N, int const start_at, std::vector<char> const break_list);
