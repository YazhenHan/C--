#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    left = mid + 1;
                    continue;
                }
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    right = mid - 1;
                    continue;
                }
            }
            else {
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                    continue;
                }
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                    continue;
                }
            }
            return nums[mid];
        }
        return -1;
    }
};