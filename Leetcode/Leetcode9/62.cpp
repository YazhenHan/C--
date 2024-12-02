#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> vv;
    int dfs(int m, int n) {
        if (m == 1 || n == 1) return 1;
        if (vv[m - 1][n - 1]) return vv[m - 1][n - 1];
        int ans;
        ans = dfs(m - 1, n) + dfs(m, n - 1);
        vv[m - 1][n - 1] = ans;
        return ans;
    }

public:
    int uniquePaths(int m, int n) {
        vv = vector<vector<int>>(m, vector<int>(n, 0));
        return dfs(m, n);
    }
};