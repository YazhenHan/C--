#include <vector>

using namespace std;

class Solution {
private:
    int getMoneyAmount(int i, int j) {
        if (i >= j) return 0;
        int ans = INT32_MAX;
        for (int k = i; k <= j; k++)
            ans = min(ans, k + max(getMoneyAmount(i, k - 1), getMoneyAmount(k + 1, j)));
        return ans;
    }
public:
    // recursion out of time
    int getMoneyAmount(int n) {
        return getMoneyAmount(1, n);
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> vv(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                vv[i][j] = j + vv[i][j - 1];
                for (int k = i; k < j; k++)
                    vv[i][j] = min(vv[i][j], k + max(vv[i][k - 1], vv[k + 1][j]));
            }
        }
        return vv[1][n];
    }
};