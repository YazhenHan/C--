#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        long long left = 0, right = sum;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) ans++;
        }
        return ans;
    }
};