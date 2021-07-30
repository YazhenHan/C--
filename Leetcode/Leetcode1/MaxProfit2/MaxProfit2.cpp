#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = INT32_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minPrice < prices[i])
                res += prices[i] - minPrice;
            minPrice = prices[i];
        }
        return res;
    }
};