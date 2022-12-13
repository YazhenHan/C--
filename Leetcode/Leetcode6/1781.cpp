#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> flags(26, 0);
            int ma = INT32_MIN;
            for (int j = i; j < s.size(); j++) {
                flags[s[j] - 'a']++;
                ma = max(ma, flags[s[j] - 'a']);
                int mi = INT32_MAX;
                for (int k = 0; k < 26; k++)
                    if (flags[k] > 0)
                        mi = min(mi, flags[k]);
                ans += (ma - mi);
            }
        }
        return ans;
    }
};