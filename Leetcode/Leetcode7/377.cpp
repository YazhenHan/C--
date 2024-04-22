#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> us;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (us.count(target)) return us[target];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans += 1;
            } else if (nums[i] < target) {
                ans += combinationSum4(nums, target - nums[i]);
            }
        }
        us.insert({target, ans});
        return ans;
    }
};