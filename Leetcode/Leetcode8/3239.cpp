#include <vector>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans1 = 0, ans2 = 0;
        for (vector<int> & row : grid) {
            int left = 0, right = row.size() - 1;
            while (left <= right) {
                if (row[left] != row[right])
                    ans1++;
                left++;
                right--;
            }
        }
        for (int j = 0; j < grid[0].size(); j++) {
            int top = 0, bottom = grid.size() - 1;
            while (top <= bottom) {
                if (grid[top][j] != grid[bottom][j])
                    ans2++;
                top++;
                bottom--;
            }
        }
        return min(ans1, ans2);
    }
};