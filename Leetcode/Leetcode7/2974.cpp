#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            ans.push_back(nums[i + 1]);
            ans.push_back(nums[i]);
        }
        return ans;
    }
};