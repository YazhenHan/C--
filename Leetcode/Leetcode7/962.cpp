#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < nums.size(); i++) {
            vp.push_back({nums[i], i});
        }
        sort(vp.begin(), vp.end());
        int temp = vp[0].second, ans = 0;
        for (int i = 1; i < vp.size(); i++) {
            ans = max(ans, vp[i].second - temp);
            temp = min(temp, vp[i].second);
        }
        return ans;
    }
};