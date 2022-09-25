#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, 
        vector<int> dp(nums.size()), dp2(nums.size());
        dp[0] = nums[0];
        dp2[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int t = nums[i] & dp[i - 1];
            if (t >= dp[i] - 1) {
                dp[i] = t;
                dp2[i] = dp[i - 1] + 1;
            } else {
                dp[i] = nums[i];
                dp2[i] = 1;
            }
            ans = max(ans, dp2[i]);
        }
        return ans;
    }
};