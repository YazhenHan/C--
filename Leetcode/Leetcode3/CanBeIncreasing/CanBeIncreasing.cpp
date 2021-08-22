#include <vector>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int k = 0;
        if (nums[0] >= nums[1]) ++k;
        for (int i = 1; i + 1 < nums.size(); ++i) {
            if (nums[i] >= nums[i + 1]) {
                if (nums[i + 1] <= nums[i - 1])
                    nums[i + 1] = nums[i];
                ++k;
            }
        }
        return k <= 1;
    }
};