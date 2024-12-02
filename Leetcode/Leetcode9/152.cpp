#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mi = nums[0], ma = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int t1 = mi, t2 = ma;
            ma = max(max(t1 * nums[i], t2 * nums[i]), nums[i]);
            mi = min(min(t1 * nums[i], t2 * nums[i]), nums[i]);
            ans = max(ans, ma);
        }
        return ans;
    }
};