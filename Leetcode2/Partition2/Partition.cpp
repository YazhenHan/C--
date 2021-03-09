#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool isA(string s, int i, int j) {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<string> forAns;
public:
    vector<vector<string>> partition(string s) {
        for (size_t i = 0; i < s.size(); i++)
        {
            for (size_t j = 0; j < s.size(); j++)
            {
                if (isA(s, i, j))
                {
                    forAns.push_back(s.substr(i, j - i + 1));
                }
                
            }
            
        }
        
    }
};