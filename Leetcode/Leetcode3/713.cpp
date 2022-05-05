#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int forAns = 1, left = 0, right = 0, ans = 0;
        while (right < nums.size()) {
            forAns = forAns * nums[right];
            while (left <= right && forAns >= k) {
                forAns /= nums[left];
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};