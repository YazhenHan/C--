#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int t = dp[i - 1] * 2;
            for (int j = i - 2; j >= 1; j--) {
                t += dp[j] * dp[i - (j + 1)];
            }
            dp[i] = t;
        }
        return dp[n];
    }
};