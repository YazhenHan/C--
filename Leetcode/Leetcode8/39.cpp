#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    void dfs(const vector<int>& candidates, int cur, vector<int> & v, int target, int sum) {
        if (sum == target) {
            ans.push_back(v);
            return;
        }
        for (int i = cur; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                v.push_back(candidates[i]);
                dfs(candidates, i, v, target, sum + candidates[i]);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(candidates, 0, v, target, 0);
        return ans;
    }
};