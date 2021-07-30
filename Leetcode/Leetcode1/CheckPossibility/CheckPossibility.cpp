#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    bool checkPossibility(vector<int> &nums, int left, int right)
    {
        nums[left] = nums[right];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool checkPossibility(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return checkPossibility(nums, i, i + 1) || checkPossibility(nums, i + 1, i);
            }
        }
        return true;
    }
};