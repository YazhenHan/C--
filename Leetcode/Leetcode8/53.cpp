#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            temp = temp >= 0 ? temp + nums[i] : nums[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};