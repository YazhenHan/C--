#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    void permute(set<vector<int >> & ans, vector<int> & forAns, const vector<int> & nums, vector<bool> flags) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (flags[i]) {
                flags[i] = false;
                forAns.push_back(nums[i]);
                if (forAns.size() == nums.size())
                    ans.insert(forAns);
                else
                    permute(ans, forAns, nums, flags);
                flags[i] = true;
                forAns.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> forAns;
        vector<bool> flags(nums.size(), true);
        permute(ans, forAns, nums, flags);
        vector<vector<int>> res;
        for (auto a : ans)
            res.push_back(a);
        return res;
    }
};