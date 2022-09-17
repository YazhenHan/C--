#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lefts(nums.size(), 1), rights(nums.size(), 1), ans(nums.size());
        for (int i = 1; i < nums.size(); i++)
            lefts[i] = lefts[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
            rights[i] = rights[i + 1] * nums[i + 1];
        for (int i = 0; i < nums.size(); i++)
            ans[i] = lefts[i] * rights[i];
        return ans;
    }
};