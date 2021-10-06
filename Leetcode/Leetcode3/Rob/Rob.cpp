#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int t1 = 0, t2 = nums.front();
        for (int i = 1; i < nums.size(); i++) {
            ans = max(t1 + nums[i], t2);
            t1 = t2;
            t2 = ans;
        }
        return t2;
    }
};