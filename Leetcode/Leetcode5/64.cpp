#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> vv = grid;
        for (int i = 1; i < m; i++)
            vv[i][0] = vv[i - 1][0] + vv[i][0];
        for (int j = 1; j < n; j++)
            vv[0][j] = vv[0][j - 1] + vv[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + vv[i][j];
        return vv[m - 1][n - 1];
    }
};