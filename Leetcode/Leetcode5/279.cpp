#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = INT32_MAX;
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j]);
            }
            dp[i] = dp[i] + 1;
        }
        return dp.back();
    }
};