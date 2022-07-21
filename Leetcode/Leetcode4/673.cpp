#include <vector>

using namespace std;

class Solution {
private:
    void dp(const vector<int>& nums, int j, vector<int>& dp1, vector<int>& dp2) {
        int longest = 0;
        for (int i = 0; i < j; i++)
            if (nums[i] < nums[j])
                longest = max(longest, dp1[i]);
        dp1[j] = longest + 1;
        for (int i = 0; i < j; i++)
            if (nums[i] < nums[j] && dp1[i] == longest)
                dp2[j] += dp2[i];
        if (dp2[j] == 0) dp2[j] = 1;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);

        int longest1 = 0, longest2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp(nums, i, dp1, dp2);
            longest1 = max(longest1, dp1[i]);
            longest2 = max(longest2, dp2[i]);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            if (dp1[i] == longest1)
                ans += dp2[i];

        return ans;
    }
};