#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto & num : nums) {
            sort(num.begin(), num.end());
        }
        int ans = 0;
        for (int j = 0; j < nums[0].size(); j++) {
            int temp = INT32_MIN;
            for (int i = 0; i < nums.size(); i++) {
                temp = max(temp, nums[i][j]);
            }
            ans += temp;
        }
        return ans;
    }
};