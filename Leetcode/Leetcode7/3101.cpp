#include <vector>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int left = 0;
        long long ans = 0;
        for (int right = left + 1; right <= nums.size(); right++) {
            if (right == nums.size() || nums[right] == nums[right - 1]) {
                for (int i = 1; i <= right - left; i++)
                    ans += right - left - i + 1;
                left = right;
            }
        }
        return ans;
    }
};