#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(3));
        dp[0] = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};