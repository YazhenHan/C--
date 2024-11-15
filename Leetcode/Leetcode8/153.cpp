#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int temp1 = INT32_MAX, temp2 = INT32_MAX;
            if (mid - 1 >= 0) temp1 = nums[mid - 1];
            if (mid + 1 < nums.size()) temp2 = nums[mid + 1];
            if (nums[mid] < temp1 && nums[mid] < temp2) return nums[mid];

            if (nums[left] > nums[right]) {
                if (nums[mid] >= nums[left]) left = mid + 1;
                else right = mid - 1;
            } else {
                return nums[left];
            }
        }
        return nums[left];
    }
};