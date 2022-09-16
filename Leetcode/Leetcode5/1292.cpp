#include <vector>

using namespace std;

class Solution {
private:
    int get(const vector<vector<int>>& vv, int i, int j) {
        int m = vv.size() - 1, n = vv.front().size() - 1;
        i = max(0, min(i, m));
        j = max(0, min(j, n));
        return vv[i][j];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat.front().size();
        vector<vector<int>> vv(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1] + mat[i - 1][j - 1];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                while (i - ans >= 0 && j - ans >= 0) {
                    int temp = get(vv, i + 1, j + 1) - get(vv, i + 1, j - ans) - get(vv, i - ans, j + 1) + get(vv, i - ans, j - ans);
                    if (temp <= threshold) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};