#include <vector>

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        vector<long long> dp = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
        for (int i = 1; i < n; i++) {
            vector<long long> dp2 = dp;
            dp2[0] = (dp[5] + dp[7]) % 1000000007;
            dp2[1] = (dp[6] + dp[8]) % 1000000007;
            dp2[2] = (dp[3] + dp[7]) % 1000000007;
            dp2[3] = (dp[2] + dp[8] + dp[9]) % 1000000007;
            dp2[5] = (dp[0] + dp[6] + dp[9]) % 1000000007;
            dp2[6] = (dp[1] + dp[5]) % 1000000007;
            dp2[7] = (dp[0] + dp[2]) % 1000000007;
            dp2[8] = (dp[1] + dp[3]) % 1000000007;
            dp2[9] = (dp[3] + dp[5]) % 1000000007;
            dp = dp2;
        }
        int ans = 0;
        for (int j = 0; j < 10; j++) {
            ans = (ans + dp[j]) % 1000000007;
        }
        return ans;
    }
};