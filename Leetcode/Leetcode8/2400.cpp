#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if (endPos - startPos > k) return 0;
        
        vector<vector<long long>> dp(2 * k + 1, vector<long long>(k + 1, 0));
        for (int i = 0; i <= k; i++) {
            dp[k + i][i] = 1;
            dp[k - i][i] = 1;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = 0; i <= k; i++) {
                long long left, right;
                if (i == k) {
                    left = 0;
                    right = 0;
                } else {
                    left = dp[k - i - 1][j - 1];
                    right = dp[k + i + 1][j - 1];
                }
                
                dp[k + i][j] = (dp[k + i - 1][j - 1] + right) % 1000000007;
                dp[k - i][j] = (left + dp[k - i + 1][j - 1]) % 1000000007;
            }
        }

        return dp[k + endPos - startPos][k];
    }
};