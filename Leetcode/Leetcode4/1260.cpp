#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                temp.push_back(grid[i][j]);
        vector<int> temp2 = temp;
        for (int i = 0; i < temp.size(); i++)
            temp2[(i + k) % temp2.size()] = temp[i];
        vector<vector<int>> ans = grid;
        k = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                ans[i][j] = temp2[k];
                k++;
            }
        }
        return ans;
    }
};