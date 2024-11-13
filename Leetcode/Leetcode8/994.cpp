#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> depth(grid.size(), vector<int>(grid[0].size(), INT32_MAX));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    vector<vector<int>> filter(grid.size(), vector<int>(grid[0].size(), 1));
                    int cur = 0;
                    while (!q.empty()) {
                        int temp = q.size();
                        for (int k = 0; k < temp; k++) {
                            pair<int, int> p = q.front();
                            if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[i].size() && filter[p.first][p.second] && grid[p.first][p.second]) {
                                depth[p.first][p.second] = min(depth[p.first][p.second], cur);
                                filter[p.first][p.second] = 0;
                                q.emplace(p.first + 1, p.second);
                                q.emplace(p.first - 1, p.second);
                                q.emplace(p.first, p.second + 1);
                                q.emplace(p.first, p.second - 1);
                                q.pop();
                            } else {
                                q.pop();
                                continue;
                            }
                        }
                        cur++;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0) {
                    if (depth[i][j] == INT32_MAX)
                        return -1;
                    else
                        ans = max(ans, depth[i][j]);
                }
            }
        }
        return ans;
    }
};