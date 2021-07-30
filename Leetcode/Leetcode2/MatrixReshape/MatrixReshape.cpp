#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() * nums[0].size() != r * c)
            return nums;
        vector<vector<int>> ans;
        for (size_t i = 0; i < r; i++)
        {
            vector<int> tempV;
            for (size_t j = 0; j < c; j++)
            {
                int temp = i * c + j;
                int temp1 = temp / nums[0].size();
                int temp2 = temp % nums[0].size();
                tempV.push_back(nums[temp1][temp2]);
            }
            ans.push_back(tempV);
        }
        return ans;
    }
};