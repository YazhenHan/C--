#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int dis = abs(nums[0]), cur = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (abs(nums[i]) <= dis)
            {
                dis = abs(nums[i]);
                cur = i;
            }
            else
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(nums[cur] * nums[cur]);
        int left = cur - 1, right = cur + 1;
        while (left >= 0 || right < nums.size())
        {
            if (left >= 0 && right < nums.size())
            {
                if (nums[left] * nums[left] < nums[right] * nums[right])
                {
                    ans.push_back(nums[left] * nums[left]);
                    left--;
                    continue;
                }
                else
                {
                    ans.push_back(nums[right] * nums[right]);
                    right++;
                    continue;
                }
            }
            if (left < 0)
            {
                ans.push_back(nums[right] * nums[right]);
                right++;
                continue;
            }
            if (right >= nums.size())
            {
                ans.push_back(nums[left] * nums[left]);
                left--;
                continue;
            }
        }
        return ans;
    }
};