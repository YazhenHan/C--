#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1;
        int res = nums.size() > 0 ? 1 : 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                len++;
                if (len > res)
                {
                    res = len;
                }
            } else {
                len = 1;
            }
        }
        return res;
    }
};