#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vv(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
            }
        }
        return vv[m - 1][n - 1];
    }
};