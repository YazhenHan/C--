#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + ans % 2 == 1) continue;
            ans++;
        }
        return ans;
    }
};