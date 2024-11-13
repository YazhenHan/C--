#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int cur, vector<int> v) {
        ans.push_back(v);
        for (int i = cur; i < nums.size(); i++) {
            v.push_back(nums[i]);
            dfs(nums, i + 1, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, 0, v);
        return ans;
    }
};