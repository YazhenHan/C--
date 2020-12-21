#include <vector>

using namespace std;

class Solution {
private:
    int minCostClimbingStairs(vector<int>& cost, int i) {
        if (i < 2)
            return 0;
        return min(cost[i] + minCostClimbingStairs(cost, i - 1), cost[i] + minCostClimbingStairs(cost, i - 2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 超时
        cost.push_back(0);
        return minCostClimbingStairs(cost, cost.size() - 1);

        vector<int> dp(cost.size() + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        return dp[cost.size()];        
    }
};