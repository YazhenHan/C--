#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans1 = -1, ans2 = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (mid - 1 == -1 || nums[mid - 1] < target) {
                ans1 = mid;
                break;
            } else right = mid - 1;
        }
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (mid + 1 == nums.size() || nums[mid + 1] > target) {
                ans2 = mid;
                break;
            } else left = mid + 1;
        }
        return {ans1, ans2};
    }
};