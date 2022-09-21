#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto num : nums)
            for (int i = 0; i + num <= target; i++)
                dp[i + num] += dp[i];
        return dp.back();
    }
};