#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> v(nums.size(), INT32_MAX);
        v[0] = 0;
        int ans = nums[0], j = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, i + nums[i]);
            while (j < v.size() && j <= ans) {
                v[j] = v[i] + 1;
                j++;
            }
        }
        return v.back();
    }
};