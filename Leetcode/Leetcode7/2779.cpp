#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1, ans = 1;
        while (r < nums.size()) {
            if (nums[l] + k >= nums[r] - k) {
                ans = max(ans, r - l + 1);
                r++;
            } else {
                while (nums[l] + k < nums[r] - k) {
                    l++;
                }
            }
        }
        return ans;
    }
};