#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN;
        int min = INT32_MAX, min2 = INT32_MAX;
        for (int num : nums)
        {
            if (num < min)
            {
                min2 = min;
                min = num;
            } else if (num < min2)
            {
                min2 = num;
            }
            if (num > max)
            {
                max3 = max2;
                max2 = max;
                max = num;
            } else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            } else if (num > max3)
            {
                max3 = num;
            }
        }
        return max3 * max2 * max > max3 * min * min2 ? max3 * max2 * max : max3 * min * min2;
    }
};