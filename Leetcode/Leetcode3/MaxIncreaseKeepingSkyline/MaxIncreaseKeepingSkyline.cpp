#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> a(grid.size(), 0), b(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                a[i] = max(a[i], grid[i][j]);
                b[j] = max(b[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                ans += min(a[i], b[j]) - grid[i][j];
        return ans;
    }
};