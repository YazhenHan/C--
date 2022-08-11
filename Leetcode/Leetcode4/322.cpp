#include <vector>

using namespace std;

class Solution {
private:
    int coinChange(vector<int>& coins, int amount, vector<int>& filter) {
        if (amount < 0) return -1;
        if (filter[amount] != -2) return filter[amount];
        int ans = INT32_MAX;
        for (auto coin : coins) {
            int temp = coinChange(coins, amount - coin, filter);
            if (temp == -1)
                continue;
            else
                ans = min(ans, temp);
        }
        filter[amount] = (ans == INT32_MAX ? -1 : ans + 1);
        return filter[amount];
    }
public:
    // Out of time
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        int ans = INT32_MAX;
        for (auto coin : coins) {
            int temp = coinChange(coins, amount - coin);
            if (temp == -1)
                continue;
            else
                ans = min(ans, temp);
        }
        return ans == INT32_MAX ? -1 : ans + 1;
    }

    // 记忆化搜索
    int coinChange(vector<int>& coins, int amount) {
        vector<int> filter(amount + 1, -2);
        filter[0] = 0;
        return coinChange(coins, amount, filter);
    }
};