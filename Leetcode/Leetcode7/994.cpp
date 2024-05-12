#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> vp;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vp.push({i, j});
                }
            }
        }

        int ans = 0;
        while (!vp.empty()){
            queue<pair<int, int>> temp;
            while (!vp.empty()) {
                int i = vp.front().first, j = vp.front().second;
                if (i + 1 < m && grid[i + 1][j] == 1) { grid[i + 1][j] = 2; temp.push({i + 1, j}); }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) { grid[i - 1][j] = 2; temp.push({i - 1, j}); }
                if (j + 1 < n && grid[i][j + 1] == 1) { grid[i][j + 1] = 2; temp.push({i, j + 1}); }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) { grid[i][j - 1] = 2; temp.push({i, j - 1}); }
                vp.pop();
            }
            vp = temp;
            if (!temp.empty()) ans++;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};