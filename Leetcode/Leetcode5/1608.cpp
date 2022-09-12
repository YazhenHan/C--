#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1, j = nums.size() - 1;
        for (int i = nums.back(); i >= 0; i--) {
            while (j >= 0 && nums[j] >= i)
                j--;
            if (nums.size() - j - 1 == i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};