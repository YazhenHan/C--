#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum == x) return nums.size();
        if (sum < x) return -1;

        int left = 0, right = 0, temp = 0, ans = INT32_MAX;
        while (right < nums.size() && left <= right) {
            temp += nums[right];
            while (temp > sum - x) {
                temp -= nums[left];
                left++;
            }
            if (temp == sum - x) {
                ans = min(ans, (int)nums.size() - (right - left + 1));
            }
            right++;
        }
        return ans == INT32_MAX ? -1 : ans;
    }
};