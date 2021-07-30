#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = 0;
        for (auto num : nums)
            total += num;
        int largest = 0;
        int i = nums.size() - 1;
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res.push_back(nums[i]);
            largest += nums[i];
            if (largest > total - largest)
                break;
        }
        return res;
    }
};