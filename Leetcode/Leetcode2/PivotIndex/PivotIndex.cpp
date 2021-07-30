#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int count = 0;
        for (auto &num : nums)
            count += num;
        int left = 0, right = count;
        for (size_t i = 0; i < nums.size(); i++)
        {
            right -= nums[i];
            if (left == right)
                return i;
            left += nums[i];
        }
        return -1;
    }
};