#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                break;
            }
        }
        if (left > right)
        {
            return {-1, -1};
        }
        for (int i = mid; i >= 0; i--)
        {
            if (nums[i] != target)
            {
                left = i + 1;
                break;
            }
        }
        for (int i = mid; i < nums.size(); i++)
        {
            if (nums[i] != target)
            {
                right = i - 1;
                break;
            }
        }
        return {left, right};
    }
};