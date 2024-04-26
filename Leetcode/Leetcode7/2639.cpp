#include <vector>
#include <string>

using namespace std;

    class Solution {
    public:
        vector<int> findColumnWidth(vector<vector<int>>& grid) {
            vector<int> ans = vector<int>(grid[0].size(), 0);
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    ans[j] = max(ans[j], int(to_string(grid[i][j]).length()));
                }
            }
            return ans;
        }
    };