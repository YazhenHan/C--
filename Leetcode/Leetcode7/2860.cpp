#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] == 0 ? 0 : 1, temp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp && nums[i - 1] < temp) ans++;
            temp++;
        }
        if (nums.back() < temp) ans++;
        return ans;
    }
};