#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size(), INT32_MAX);
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                res[i] = 0;
                for (int left = i - 1; left >= 0 && res[left] != 0; left--)
                {
                    res[left] = min(res[left], res[left + 1] + 1);
                }
                for (int right = i + 1; right < res.size() && res[right] != 0; right++)
                {
                    res[right] = min(res[right], res[right - 1] + 1);
                }
            }
        }
        return res;
    }
};