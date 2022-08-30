#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int ans = 0;
        int sub = nums[1] - nums[0], left = 0;
        vector<int> dp(nums.size());
        for (int i = 2; i < nums.size(); i++) {
            int temp = nums[i] - nums[i - 1];
            if (temp == sub) {
                ans += (i - left - 1);
            } else {
                sub = temp;
                left = i - 1;
            }
        }
        return ans;
    }
};