#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        stack<int> s;
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i])
                s.pop();
            ans[i] = s.empty() ? prices[i] : prices[i] - s.top();
            s.push(prices[i]);
        }
        return ans;
    }
};