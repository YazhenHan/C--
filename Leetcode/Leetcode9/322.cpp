#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount + 1, INT32_MAX);
        v[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            int ans = INT32_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    ans = min(ans, v[i - coins[j]]);
                }
            }
            if (ans != INT32_MAX)
                v[i] = ans + 1;
        }
        if (v.back() == INT32_MAX) return -1;
        return v.back();
    }
};