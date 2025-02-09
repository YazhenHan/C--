#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        void dfs(vector<vector<int>> & ans, vector<int> & forAns, unordered_map<int, int> & um) {
        if (um.empty()) {
            ans.push_back(forAns);
            return;
        }
    
        unordered_map<int, int> um2 = um;
        for (auto temp : um2) {
            forAns.push_back(temp.first);
            um[temp.first]--;
            if (um[temp.first] == 0) um.erase(temp.first);
            dfs(ans, forAns, um);
            um[temp.first]++;
            forAns.pop_back();
        }
    }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            unordered_map<int, int> um;
            for (int num : nums) um[num]++;
            vector<vector<int>> ans;
            vector<int> forAns;
            dfs(ans, forAns, um);
            return ans;
        }
    };