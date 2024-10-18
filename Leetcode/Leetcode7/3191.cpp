#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> temp = nums;
        int ans1 = 0, ans2 = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 1) {
                i++;
                continue;
            }
            if (i + 2 >= nums.size()) return -1;
            nums[i] = 1 - nums[i];
            nums[i + 1] = 1 - nums[i + 1];
            nums[i + 2] = 1 - nums[i + 2];
            ans1++;
            i++;
        }

        i = temp.size() - 1;
        while (i >= 0) {
            if (temp[i] == 1) {
                i--;
                continue;
            }
            if (i - 2 < 0) return -1;
            temp[i] = 1 - temp[i];
            temp[i - 1] = 1 - temp[i - 1];
            temp[i - 2] = 1 - temp[i - 2];
            ans2++;
            i--;
        }

        return min(ans1, ans2);
    }
};