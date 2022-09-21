#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        for (auto candidate : candidates)
            for (int i = 0; i + candidate <= target; i++)
                if (i == 0)
                    dp[i + candidate].push_back({candidate});
                else
                    for (auto t : dp[i]) {
                        dp[i + candidate].push_back(t);
                        dp[i + candidate].back().push_back(candidate);
                    }
        return dp.back();
    }
};