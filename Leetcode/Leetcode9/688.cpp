#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<vector<double>>> vvv;
    double dfs(int n, int k, int row, int column) {
        if (k == 0) return 1.0;

        if (vvv[k - 1][min(n - 1 - row, row)][min(n - 1 - column, column)] > -1.0) return vvv[k - 1][min(n - 1 - row, row)][min(n - 1 - column, column)];

        double ans = 0.0;
        if (row + 2 < n && column + 1 < n) ans += 0.125 * dfs(n, k - 1, row + 2, column + 1);
        if (row + 1 < n && column + 2 < n) ans += 0.125 * dfs(n, k - 1, row + 1, column + 2);
        if (row + 2 < n && column - 1 >= 0) ans += 0.125 * dfs(n, k - 1, row + 2, column - 1);
        if (row + 1 < n && column - 2 >= 0) ans += 0.125 * dfs(n, k - 1, row + 1, column - 2);
        if (row - 2 >= 0 && column + 1 < n) ans += 0.125 * dfs(n, k - 1, row - 2, column + 1);
        if (row - 1 >= 0 && column + 2 < n) ans += 0.125 * dfs(n, k - 1, row - 1, column + 2);
        if (row - 2 >= 0 && column - 1 >= 0) ans += 0.125 * dfs(n, k - 1, row - 2, column - 1);
        if (row - 1 >= 0 && column - 2 >= 0) ans += 0.125 * dfs(n, k - 1, row - 1, column - 2);
        vvv[k - 1][min(n - 1 - row, row)][min(n - 1 - column, column)] = ans;
        return ans;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vvv = vector<vector<vector<double>>>(k, vector<vector<double>>(ceil(n / 2.0), vector<double>(ceil(n / 2.0), -1.0)));
        return dfs(n, k, row, column);
    }
};