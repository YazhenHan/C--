#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<vector<int>>> um;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (um.count(groupSizes[i])) {
                if (um[groupSizes[i]].empty() || um[groupSizes[i]].back().size() == groupSizes[i]) {
                    um[groupSizes[i]].push_back({i});
                } else {
                    um[groupSizes[i]].back().push_back(i);
                }
            } else {
                um[groupSizes[i]].push_back({i});
            }
        }
        vector<vector<int>> ans;
        for (auto p : um) {
            for (auto t : p.second)
                ans.push_back(t);
        }
        return ans;
    }
};