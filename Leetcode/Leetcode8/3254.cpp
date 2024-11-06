#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> ans(nums.size() - k + 1);
        int temp = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (i - temp >= k && nums[i] - nums[i - 1] == 1) {
                ans[i - k + 1] = nums[i];
                continue;
            }
            if (i >= k - 1)
                ans[i - k + 1] = -1;
            if (nums[i] - nums[i - 1] != 1)
                temp = i - 1;
        }
        return ans;
    }
};