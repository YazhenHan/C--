#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> v(grid.size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            int k = 0;
            for (int j = grid.size() - 1; j >= 0 && grid[i][j] == 0; j--)
                k++;
            v[i] = k;
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            bool flag = false;
            for (int j = i; j < grid.size(); j++) {
                if (v[j] >= grid.size() - i - 1) {
                    ans += (j - i);
                    for (int k = j; k > i; k--) {
                        swap(v[k], v[k - 1]);
                    }
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return -1;
        }
        return ans;
    }
};