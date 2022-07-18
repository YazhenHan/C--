#include <vector>

using namespace std;

class Solution {
private:
    int f(const vector<int>& nums, int j, vector<int>& dp) {
        int ans = 0;
        for (int i = 0; i < j; i++)
            if (nums[i] < nums[j])
                ans = max(ans, dp[i]);
        dp[j] = ans + 1;
        return dp[j];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans = max(ans, f(nums, i, dp));
        return ans;
    }
};