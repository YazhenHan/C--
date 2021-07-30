#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int forAns = INT32_MAX;
        int ans;
        // int last = INT32_MAX;
        for (size_t i = 0; i + 2 < nums.size(); i++)
        {
            for (size_t j = i + 1; j + 1 < nums.size(); j++)
            {
                for (size_t k = j + 1; k < nums.size(); k++)
                {
                    int temp = nums[i] + nums[j] + nums[k];
                    if (abs(temp - target) < forAns)
                    {
                        ans = temp;
                        forAns = abs(temp - target);
                    }
                    // if (abs(temp - target) > last)
                    // {
                    //     break;
                    // }
                    // last = abs(temp - target);
                }
                
            }
            
        }
        return ans;
    }
};