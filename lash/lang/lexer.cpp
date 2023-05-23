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
    string type;
    string value;
    Token(string tType, string tValue)
    {
        type = tType;
        value = tValue;
    }
};

vector<string>
lex()
{
    vector<string> ret;

    return ret;
}