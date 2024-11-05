#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lefts(n), right(n), ans(n);
        lefts[0] = nums[0];
        right[n - 1] = nums.back();
        for (int i = 1; i < n; i++) {
            lefts[i] = lefts[i - 1] * nums[i];
            right[n - 1 - i] = right[n - i] * nums[n - 1 - i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) ans[0] = right[1];
            else if (i == n - 1) ans[i] = lefts[n - 2];
            else ans[i] = lefts[i - 1] * right[i + 1];
        }

        return ans;
    }
};