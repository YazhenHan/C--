#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        ans[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) ans[i][0] = ans[i - 1][0] + grid[i][0];
        for (int j = 1; j < grid[0].size(); j++) ans[0][j] = ans[0][j - 1] + grid[0][j];
        
        for (int i = 1; i < ans.size(); i++) {
            for (int j = 1; j < ans[i].size(); j++) {
                ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
            }
        }
        return ans.back().back();
    }
};