#include <vector>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT32_MAX;
        for (int right = 0; right < nums.size(); right++) {
            int temp = 0;
            for (int left = right; left >= 0; left--) {
                temp |= nums[left];
                if (temp >= k) {
                    ans = min(ans, right - left + 1);
                    break;
                }
            }
            if (ans == 1) break;
        }
        if (ans == INT32_MAX) return -1;
        return ans;
    }
};