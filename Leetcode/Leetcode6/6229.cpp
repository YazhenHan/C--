#include <vector>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans = nums;
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                ans[i] *= 2;
                ans[i + 1] = 0;
            }
        }
        int left = 0, right = 0;
        while (right < ans.size()) {
            if (ans[right] == 0) {
                right++;
                continue;
            }
            ans[left] = ans[right];
            left++;
            right++;
        }
        while (left < ans.size()) {
            ans[left] = 0;
            left++;
        }
        return ans;
    }
};