#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums.front());
        for (int i = 1; i < nums.size(); i++)
            ans.push_back(ans.back() + nums[i]);
        return ans;
    }
};