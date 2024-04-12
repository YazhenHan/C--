#include <vector>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        vector<bool> v(grid.size(), true);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    v[j] = false;
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) {
                return i;
            }
        }
        return -1;
    }
};