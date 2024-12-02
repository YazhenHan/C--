#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size());
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    temp = max(temp, v[j]);
                }
            }
            v[i] = temp + 1;
            ans = max(ans, v[i]);
        }
        return ans;
    }
};