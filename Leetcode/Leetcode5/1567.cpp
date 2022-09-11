#include <vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, temp1 = 0, temp2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                temp1 = temp1 + 1;
                temp2 = temp2 > 0 ? temp2 + 1 : 0;
            }
            else if (nums[i] < 0) {
                int temp = temp1;
                temp1 = temp2 > 0 ? temp2 + 1 : 0;
                temp2 = temp + 1;
            }
            else {
                temp1 = 0;
                temp2 = 0;
            }
            ans = max(ans, temp1);
        }
        return ans;
    }
};