#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0)
            return ans;
        int left = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i-1] + 1)
            {
                string temp;
                if (nums[i-1] != left)
                    temp = to_string(left) + "->" + to_string(nums[i-1]);
                else
                    temp = to_string(left);
                ans.push_back(temp);
                left = nums[i];
            }
        }
        string temp;
        if (nums.back() != left)
            temp = to_string(left) + "->" + to_string(nums.back());
        else
            temp = to_string(left);
        ans.push_back(temp);
        return ans;
    }
};