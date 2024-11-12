#include <vector>

using namespace std;

class Solution {
private:
    void dfs(const vector<vector<char>>& grid, vector<vector<int>> & dp, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1' && dp[i][j]) dp[i][j] = 0;
        else return;
        dfs(grid, dp, i + 1, j);
        dfs(grid, dp, i - 1, j);
        dfs(grid, dp, i, j + 1);
        dfs(grid, dp, i, j - 1);        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 1));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && dp[i][j]) {
                    ans++;
                    dfs(grid, dp, i, j);
                }
            }
        }
        return ans;
    }
};