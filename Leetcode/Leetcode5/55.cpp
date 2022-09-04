#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= ans) {
                ans = max(ans, i + nums[i]);
                if (ans >= nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};