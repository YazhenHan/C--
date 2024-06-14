#include <vector>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        bool flag = nums[0] % 2;
        long long ans1 = nums[0], ans2 = INT32_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == flag) {
                ans1 = max(ans1 + nums[i], ans2 + nums[i] - x);
            } else {
                ans2 = max(ans2 + nums[i], ans1 + nums[i] - x);
            }
        }
        return max(ans1, ans2);
    }
};