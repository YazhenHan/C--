#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT32_MIN;
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid.back().size() + 1, INT32_MAX));
        for (int i = 1; i <= grid.size(); i++) {
            for (int j = 1; j <= grid.back().size(); j++) {
                ans = max(ans, max(grid[i -1][j - 1] - dp[i - 1][j], grid[i - 1][j - 1] - dp[i][j - 1]));
                dp[i][j] = min(grid[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return ans;
    }
};