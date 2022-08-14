#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid.size() - 1; j++) {
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i - 1][j - 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i - 1][j]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i - 1][j + 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i][j - 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i][j]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i][j + 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + 1][j - 1]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + 1][j]);
                ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + 1][j + 1]);
            }
        }
        return ans;
    }
};