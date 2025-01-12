#include <vector>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        auto maxlen = [&](int k) -> int {
            int ans = 0;
            for (int candidate : candidates) {
                if (candidate & (1 << k)) {
                    ans++;
                }
            }
            return ans;
        };

        int ans = 0;
        for (int i = 0; i < 24; i++) {
            ans = max(ans, maxlen(i));
        }
        return ans;
    }
};