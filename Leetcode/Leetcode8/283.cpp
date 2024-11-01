#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }
        while (cur < nums.size()) {
            nums[cur++] = 0;
        }
    }
};