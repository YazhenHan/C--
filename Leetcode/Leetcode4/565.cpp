#include <vector>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<bool> flags(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            int temp = i, tans = 0;
            while (!flags[temp]) {
                tans++;
                flags[temp] = true;
                temp = nums[temp];
            }
            ans = max(ans, tans);
        }
        return ans;
    }
};