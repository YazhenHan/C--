#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 0);
        int ans = 0;
        for (int i = 0; i < envelopes.size(); i++) {
            int temp = 0;
            for (int j = 0; j < i; j++)
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    temp = max(temp, dp[j]);
                else if (envelopes[j][0] >= envelopes[i][0])
                    break;
            dp[i] = temp + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto & e1, const auto & e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < envelopes.size(); i++) {
            int num = envelopes[i][1];
            if (num > f.back())
                f.push_back(num);
            else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};