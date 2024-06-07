#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> flags;
    int maxOperations(vector<int>& nums, int left, int right, int temp) {
        if (right - left < 1) return 0;
        if (flags[left][right] != -1) return flags[left][right];
        int ans1 = 0, ans2 = 0, ans3 = 0;
        if (nums[left] + nums[left + 1] == temp)
            ans1 = maxOperations(nums, left + 2, right, temp) + 1;
        if (nums[left] + nums[right] == temp)
            ans2 = maxOperations(nums, left + 1, right - 1, temp) + 1;
        if (nums[right] + nums[right - 1] == temp)
            ans3 = maxOperations(nums, left, right - 2, temp) + 1;
        int ans = max(ans1, max(ans2, ans3));
        flags[left][right] = ans;
        return ans;
    }
public:
    int maxOperations(vector<int>& nums) {
        flags = vector<vector<int>>(nums.size(), vector<int>(nums.size(), - 1));
        int t1 = nums[0] + nums[1];
        int t2 = nums.front() + nums.back();
        int t3 = nums[nums.size() - 1] + nums[nums.size() - 2];
        return max(maxOperations(nums, 2, nums.size() - 1, t1), 
        max(maxOperations(nums, 1, nums.size() - 2, t2), maxOperations(nums, 0, nums.size() - 3, t3))) + 1;
    }
};