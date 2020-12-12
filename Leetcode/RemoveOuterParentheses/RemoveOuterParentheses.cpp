#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int flag = 0;
        int left = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
            {
                flag++;
            } else {
                flag--;
                if (flag == 0)
                {
                    for (int j = left + 1; j < i; j++)
                    {
                        res.push_back(S[j]);
                    }
                    left = i + 1;
                }
            }
        }
        return res;
    }
};