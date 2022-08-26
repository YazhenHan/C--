#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> umm;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = nums[i] - nums[j];
                if (umm.count(d) && umm[d].count(j))
                    umm[d][i] = umm[d][j] + 1;
                else
                    umm[d][i] = 2;
                ans = max(ans, umm[d][i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<vector<int>> dp(1003, vector<int>(1003, 0));
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = 2 * nums[i] - nums[j];
                if (um.count(k))
                    dp[i][j] = dp[um[k]][i] + 1;
                ans = max(ans, dp[i][j]);
            }
            um[nums[i]] = i;
        }
        return ans + 2;
    }
};