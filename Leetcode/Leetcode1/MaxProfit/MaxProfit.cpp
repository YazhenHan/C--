#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT32_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] - min > res)
                res = prices[i] - min;
            if (prices[i] < min)
                min = prices[i];
        }
        return res;
    }
};