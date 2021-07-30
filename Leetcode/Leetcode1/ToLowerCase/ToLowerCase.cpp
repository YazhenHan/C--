#include <string>

using namespace std;

class Solution
{
public:
    string toLowerCase(string str)
    {
        string cg;
        for(auto s : str)
        {
            cg.push_back(tolower(s));
        }
        return cg;
    }
};