#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (stk.empty() || nums[i] <= nums[stk.top()])
            {
                stk.push(i);
            }
            else
            {
                while (!stk.empty() && nums[stk.top()] < nums[i])
                {
                    ans[stk.top()] = nums[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i])
            {
                ans[stk.top()] = nums[i];
                stk.pop();
            }
        }
        
        return ans;
    }
};