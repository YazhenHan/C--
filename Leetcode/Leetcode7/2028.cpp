#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n, 1);
        int total = (rolls.size() + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (total > n * 6 || total < n)
            return vector<int>();
        total -= n;
        for (int i = 0; i < n; i++) {
            ans[i] += min(total, 5);
            total -= (ans[i] - 1);
        }
        return ans;
    }
};