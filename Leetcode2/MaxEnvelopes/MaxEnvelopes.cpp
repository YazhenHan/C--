#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp1(vector<int>& envelop1, vector<int>& envelop2) {
        if (envelop1[0] < envelop2[0])
            return true;
        if (envelop1[0] == envelop2[0] && envelop1[1] < envelop2[1])
            return true;
        return false;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0)
            return 0;
        
        int ans1 = 1;
        sort(envelopes.begin(), envelopes.end(), cmp1);
        vector<int> dp1(envelopes.size(), 1);
        for (size_t i = 1; i < envelopes.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp1[i] = max(dp1[i], dp1[j] + 1);
            ans1 = max(dp1[i], ans1);
        }

        return ans1;
    }
};