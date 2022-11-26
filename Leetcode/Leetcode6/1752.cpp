#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (flag)
                    return false;
                else
                    flag = true;
            }
        }
        if (flag)
            return nums[0] >= nums.back();
        return true;
    }
};