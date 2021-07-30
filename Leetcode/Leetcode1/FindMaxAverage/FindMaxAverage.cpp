#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int max = sum;
        for (int i = k; i < nums.size(); i++)
        {
            sum = sum - nums[i - k] + nums[i];
            if (sum > max)
            {
                max = sum;
            }
        }
        return max / (double)k;
    }
};