#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        int flag = 1;
        for (size_t i = 1; i <= num; i++)
        {
            if (i == flag)
            {
                ans.push_back(1);
                flag *= 2;
                continue;
            }
            ans.push_back(ans[i - flag / 2] + ans[flag / 2]);
        }
        return ans;
    }
};