#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], temp1 = nums[0], temp2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = max(temp1 * nums[i], max(temp2 * nums[i], nums[i]));
            temp2 = min(temp1 * nums[i], min(temp2 * nums[i], nums[i]));
            temp1 = temp;
            ans = max(ans, temp1);
        }
        return ans;
    }
};