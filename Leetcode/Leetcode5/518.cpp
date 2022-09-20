#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins)
            for (int i = 0; i + coin <= amount; i++)
                dp[i + coin] += dp[i];
        return dp.back();
    }
};