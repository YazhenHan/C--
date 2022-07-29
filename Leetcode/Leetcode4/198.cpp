#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int t1 = 0, t2 = nums.front();
        for (int i = 1; i < nums.size(); i++) {
            t1 = max(t1 + nums[i], t2);
            swap(t1, t2);
        }
        return max(t1, t2);
    }
};