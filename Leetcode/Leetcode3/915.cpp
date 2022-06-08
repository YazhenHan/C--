#include <vector>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans = 1, max1 = nums.front(), max2 = nums.front();
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            max2 = max(max2, nums[i]);
            if (nums[i] < max1) {
                max1 = max2;
                flag = true;
            }
            else if (flag) {
                ans = i;
                flag = false;
            }
        }
        return ans;
    }
};