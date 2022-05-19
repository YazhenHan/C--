#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int middle = nums[nums.size() / 2];
        int ans = 0;
        for (auto num : nums)
            ans += max(num, middle) - min(num, middle);
        return ans;
    }
};