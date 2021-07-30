#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int keep[50000] = {0};
        int on = 0;
        vector<int> comming;
        for (int &num : nums)
        {
            keep[num]++;
            if (keep[num] > on)
            {
                on = keep[num];
            }
        }
        int cg = 50000;
        for(int i = 0;i < 50000;i++)
        {
            if (keep[i] == on)
            {
                cout << i << endl;
                int left = 0,right = nums.size() - 1;
                while (nums[left] != i || nums[right] != i)
                {
                    if(nums[left] != i)
                    {
                        left++;
                    }
                    if(nums[right] != i)
                    {
                        right--;
                    }
                }
                cout << left << " " << right << endl;
                if(right - left + 1 < cg)
                {
                    cg = right - left + 1;
                }
            }
        }
        return cg;
    }
};

int main()
{
    vector<int> nums = {1,2,2,3,1,4,2};
    Solution sol;
    cout << sol.findShortestSubArray(nums) << endl;
}