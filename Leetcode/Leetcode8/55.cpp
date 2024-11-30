#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 0; i <= ans && i < nums.size(); i++) {
            ans = max(ans, i + nums[i]);
        }
        return ans >= nums.size() - 1;
    }
};