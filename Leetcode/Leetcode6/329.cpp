#include <vector>

using namespace std;

class Solution {
private:
    int ans = 1;
    void dfs(const vector<vector<int>>& matrix, int i, int j, int previ, int prevj, vector<vector<int>> & dp) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size() || matrix[i][j] <= matrix[previ][prevj] || dp[i][j] > dp[previ][prevj])
            return;
        dp[i][j] = dp[previ][prevj] + 1;
        ans = max(ans, dp[i][j]);
        dfs(matrix, i + 1, j, i, j, dp);
        dfs(matrix, i - 1, j, i, j, dp);
        dfs(matrix, i, j + 1, i, j, dp);
        dfs(matrix, i, j - 1, i, j, dp);
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.front().size(), 1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                dfs(matrix, i + 1, j, i, j, dp);
                dfs(matrix, i - 1, j, i, j, dp);
                dfs(matrix, i, j + 1, i, j, dp);
                dfs(matrix, i, j - 1, i, j, dp);
            }
        }
        return ans;
    }
};