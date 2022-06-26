#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(3);
        for (int i = 0; i < 3; i++)
            dp[i] = costs[0][i];
        for (int i = 1; i < costs.size(); i++) {
            vector<int> dpnew(3);
            for (int j = 0; j < 3; j++)
                dpnew[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
            dp = dpnew;
        }
        return min(min(dp[0], dp[1]), dp[2]);
    }
};