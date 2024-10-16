#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double ans = INT32_MAX;
        for (int i = 0; i <= nums.size() / 2; i++) {
            ans = min(ans, (double)(nums[i] + nums[nums.size() - i - 1]) / 2);
        }
        return ans;
    }
};