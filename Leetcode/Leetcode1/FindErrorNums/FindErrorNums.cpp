#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int flag[10000] = {0};
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            flag[nums[i] - 1]++;
            if (flag[nums[i] - 1] == 2)
            {
                res.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (flag[i] == 0)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    nums = sol.findErrorNums(nums);
    cout << nums[0] << " " << nums[1] << endl;
    return 0;
}