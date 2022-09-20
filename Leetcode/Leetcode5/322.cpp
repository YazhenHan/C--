#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT32_MAX;
            for (auto coin : coins)
                if (i >= coin && dp[i - coin] != INT32_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp.back() == INT32_MAX ? -1 : dp.back();
    }
};