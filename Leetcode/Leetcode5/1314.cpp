#include <vector>

using namespace std;

class Solution {
private:
    int get(const vector<vector<int>>& vv, int m, int n, int x, int y) {
        x = max(0, min(x, m));
        y = max(0, min(n, y));
        return vv[x][y];
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vv(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = get(vv, m, n, i + k + 1, j + k + 1) - get(vv, m, n, i + k + 1, j - k) - get(vv, m, n, i - k, j + k + 1) + get(vv, m, n, i - k, j - k);
            }
        }
        return ans;
    }
};