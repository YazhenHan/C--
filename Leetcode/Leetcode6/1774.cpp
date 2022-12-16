#include <vector>

using namespace std;

class Solution {
private:
    void dfs(const vector<int>& toppingCosts, int p, int curCost, int& ans, const int& target) {
        if (abs(ans - target) < curCost - target)
            return;
        else if (abs(ans - target) >= abs(curCost - target)) {
            if (abs(ans - target) > abs(curCost - target))
                ans = curCost;
            else
                ans = min(ans, curCost);
        }
        if (p == toppingCosts.size())
            return;
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, ans, target);
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], ans, target);
        dfs(toppingCosts, p + 1, curCost, ans, target);
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = *min_element(baseCosts.begin(), baseCosts.end());
        for (auto& b : baseCosts)
            dfs(toppingCosts, 0, b, ans, target);
        return ans;
    }
};