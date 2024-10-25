#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int maxTotalReward(vector<int>& rewardValues, int i, int c) {
        if (i == rewardValues.size()) return 0;
        int ans1 = 0;
        if (c < rewardValues[i]) {
            ans1 = rewardValues[i] + maxTotalReward(rewardValues, i + 1, c + rewardValues[i]);
        }
        int ans2 = maxTotalReward(rewardValues, i + 1, c);
        return max(ans1, ans2);
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        return maxTotalReward(rewardValues, 0, 0);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<int> dp(rewardValues.back() * 2, 0);
        dp[0] = 1;
        for (int rewardValue : rewardValues) {
            for (int i = rewardValue * 2 - 1; i >= rewardValue; i--) {
                if (dp[i - rewardValue]) {
                    dp[i] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = rewardValues.back() * 2 - 1; i >= 0; i--) {
            if (dp[i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};