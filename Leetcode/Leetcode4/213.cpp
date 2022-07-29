#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        int t1 = 0, t2 = nums.front();
        for (int i = 1; i < nums.size() - 1; i++) {
            t1 = max(t1 + nums[i], t2);
            swap(t1, t2);
        }
        int ans1 = max(t1, t2);
        t1 = 0;
        t2 = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            t1 = max(t1 + nums[i], t2);
            swap(t1, t2);
        }
        int ans2 = max(t1, t2);
        return max(ans1, ans2);
    }
};