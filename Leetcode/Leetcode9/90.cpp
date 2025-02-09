#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> forAns;
    vector<vector<int>> ans;
    void dfs(bool flag, int cur, const vector<int> & nums) {
        if (cur == nums.size()) {
            ans.push_back(forAns);
            return;
        }
        dfs(false, cur + 1, nums);
        if (!flag && cur > 0 && nums[cur] == nums[cur - 1]) return;
        forAns.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        forAns.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};