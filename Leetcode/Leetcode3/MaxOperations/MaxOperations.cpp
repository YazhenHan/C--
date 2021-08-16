#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, ans = 0;
        while (left < right)
        {
            if (nums[left] + nums[right] == k) {
                left++; right--; ans++;
            }
            else if (nums[left] + nums[right] < k) left++;
            else right--;
        }
        return ans;
    }
};