#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = nums.size() - k; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        for (int i = nums.size() - k - 1; i >= 0; i--) {
            if (nums[i] > ans.front()) continue;
            for (int j = 0; j < ans.size(); j++) {
                if (j + 1 == ans.size() || ans[j] > ans[j + 1]) {
                    for (int k = j - 1; k >= 0; k--) {
                        ans[k + 1] = ans[k];
                    }
                    break;
                }
            }
            ans[0] = nums[i];
        }
        return ans;
    }
};