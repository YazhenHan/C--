#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        int num = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '-')
            {
                num++;
            }
        }
        int bnum = (S.size() - num) % K;
        string res;
        int count = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '-')
            {
                continue;
            }
            if (bnum != 0 && count == bnum || count == K)
            {
                res.push_back('-');
                count = 0;
                bnum = K + 1;
            }
            res.push_back(toupper(S[i]));
            count++;
        }
        return res;
    }
};

int main()
{
    string S = "2-5g-3-J";
    int K = 2;
    Solution sol;
    cout << sol.licenseKeyFormatting(S, K) << endl;
    return 0;
}