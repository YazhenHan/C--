#include <vector>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int cnt = grid[i][j] + grid[m - 1 - i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][n - 1 - j];
                ans += min(cnt, 4 - cnt);
            }
        }

        int diff = 0, cnt = 0;
        if (m % 2 != 0) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[m / 2][j] != grid[m / 2][n - 1 - j])
                    diff++;
                else
                    cnt += grid[m / 2][j] * 2;
            }
        }
        if (n % 2 != 0) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] != grid[m - 1 - i][n / 2])
                    diff++;
                else
                    cnt += grid[i][n / 2] * 2;
            }
        }
        if (m % 2 != 0 && n % 2 != 0) {
            ans += grid[m / 2][n / 2];
        }
        if (diff > 0) ans += diff;
        else ans += cnt % 4;
        return ans;
    }
};