#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid.front().size();
        vector<vector<int>> vv(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            vv[i][0] = obstacleGrid[i][0] ? 0 : vv[i - 1][0];
        for (int j = 1; j < n; j++)
            vv[0][j] = obstacleGrid[0][j] ? 0 : vv[0][j - 1];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                vv[i][j] = obstacleGrid[i][j] ? 0 : (vv[i - 1][j] + vv[i][j - 1]);
        return vv[m - 1][n - 1];
    }
};