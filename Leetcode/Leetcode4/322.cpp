#include <vector>

using namespace std;

class Solution {
public:
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
};