#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1 = -prices[0], t2 = 0, t3 = 0;
        for (int i = 1; i < prices.size(); i++) {
            int t = t1;
            t1 = max(t1, t3 - prices[i]);
            t3 = max(t2, t3);
            t2 = t + prices[i];
        }
        return max(t2, t3);
    }
};