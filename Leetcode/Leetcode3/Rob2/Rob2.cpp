#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int ans = 0;
        int t1 = 0, t2 = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            ans = max(t1 + nums[i], t2);
            t1 = t2;
            t2 = ans;
        }

        int t3 = 0, t4 = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            ans = max(t3 + nums[i], t4);
            t3 = t4;
            t4 = ans;
        }

        return max(t2, t4);
    }
};