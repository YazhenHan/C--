#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int wiggleMaxLength(vector<int>& nums, int i, bool flag) {
        if (nums.size() - i < 2)
        {
            return nums.size() - i;
        }
        if (nums.size() - i == 2)
        {
            return nums[i] == nums[i+1] ? 1 : 2;
        }
        if (flag)
        {
            int res = 1;
            int temp = nums[i];
            int flag2 = 0;
            for (int j = i + 1; j + 1 < nums.size(); j++)
            {
                if (nums[j] > nums[j-1] && nums[j] > nums[j+1])
                {
                    res++;
                    temp = nums[j];
                    flag2 = -1;
                    continue;
                }
                if (nums[j] < nums[j-1] && nums[j] < nums[j+1])
                {
                    res++;
                    temp = nums[j];
                    flag2 = 1;
                    continue;
                }
                if ((flag2 == 0 ||flag2 == -1) && nums[j] != temp && nums[j] == nums[j-1] && nums[j] < nums[j+1])
                {
                    res++;
                    temp = nums[j];
                    flag2 = 1;
                    continue;
                }
                if ((flag2 == 0 ||flag2 == 1) && nums[j] != temp && nums[j] == nums[j-1] && nums[j] > nums[j+1])
                {
                    res++;
                    temp = nums[j];
                    flag2 = -1;
                    continue;
                }
            }
            if(nums[nums.size() - 1] != temp)
                res++;
            return res;
        } else
        {
            return max(wiggleMaxLength(nums, i + 1, true), wiggleMaxLength(nums, i + 1, false));
        }
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        return max(wiggleMaxLength(nums, 0, true), wiggleMaxLength(nums, 0, false));
    }
};