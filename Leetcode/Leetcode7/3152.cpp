#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> lefts, rights;
        int left = 0;
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] % 2 == nums[right - 1] % 2) {
                lefts.push_back(left);
                rights.push_back(right - 1);
                left = right;
            }
        }
        lefts.push_back(left);
        rights.push_back(nums.size() - 1);

        vector<bool> ans;
        for (auto& query : queries) {
            int i = 0, j = lefts.size() - 1, result = -1;
            while (i <= j) {
                int k = i + (j - i) / 2;
                if (lefts[k] <= query[0]) {
                    result = k;
                    i = k + 1;
                } else {
                    j = k - 1;
                }
            }
            if (result == -1) {
                ans.push_back(false);
                continue;
            }
            ans.push_back(rights[result] >= query[1]);
        }
        return ans;
    }
};