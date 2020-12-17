#include <string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int r = 0;
        int l = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
                r++;
            else
                l++;
            if (r == l)
                res++;
        }
        return res;
    }
};