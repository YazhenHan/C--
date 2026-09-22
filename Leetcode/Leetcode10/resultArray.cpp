#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(k, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][nums[i] % k]++;
            for (int j = 0; j < k; j++) {
                if (i - 1 >= 0) {
                    dp[i][(long long)nums[i] * j % k] += dp[i - 1][j];
                }
            }
        }

        vector<long long> ans(k, 0);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < nums.size(); j++) {
                ans[i] += dp[j][i];
            }
        }
        return ans;
    }
};