#ifndef Token_h
#define Token_h
#include <string>
using namespace std;

class Token
{

public:
    static void writeTokenFile(const string &token);
    static string readTokenFile();
};

#endif