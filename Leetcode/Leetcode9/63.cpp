#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp = obstacleGrid;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    int m = i > 0 ? dp[i - 1][j] : 0;
                    int n = j > 0 ? dp[i][j - 1] : 0;
                    dp[i][j] = m + n;
                }
                if (i == 0 && j == 0 && obstacleGrid[i][j] != 1) dp[i][j] = 1;
            }
        }
        return dp.back().back();
    }
};