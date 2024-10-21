#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; i++) {
            int a = max(nums[n - 1] - k, nums[i] + k);
            int b = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, a - b);
        }
        return ans;
    }
};