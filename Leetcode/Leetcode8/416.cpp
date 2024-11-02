#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, maxNum = 0;
        for (auto num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum % 2 != 0) return false;
        if (maxNum > sum / 2) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, false));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = true;
            dp[i][nums[i]] = true;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j <= sum / 2; j++) {
                if (j - nums[i] >= 0) dp[i][j] = dp[i - 1][j - nums[i]] | dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp.back()[sum / 2];
    }
};