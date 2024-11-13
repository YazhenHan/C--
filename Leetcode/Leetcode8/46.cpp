#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    void dfs(const vector<int> & nums, unordered_set<int> & us, vector<int> & v) {
        if (us.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for (auto num : nums) {
            if (!us.count(num)) {
                us.insert(num);
                v.push_back(num);
                dfs(nums, us, v);
                us.erase(num);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> us;
        vector<int> v;
        dfs(nums, us, v);
        return ans;
    }
};