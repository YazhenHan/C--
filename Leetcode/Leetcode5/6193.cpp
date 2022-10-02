#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = INT32_MIN;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[i].size() - 1; j++) {
                int t = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + grid[i][j] 
                    + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                ans = max(ans, t);
            }
        }
        return ans;
    }
};