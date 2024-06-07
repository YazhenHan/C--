#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 1, temp = nums[0] + nums[1];
        for (int i = 2; i + 1 < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] == temp)
                ans++;
            else
                break;
        }
        return ans;
    }
};