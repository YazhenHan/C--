#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> um;
        for (auto& match : matches) {
            if (!um.count(match[0])) {
                um[match[0]] = 1;
            }
            if (um.count(match[1])) {
                if (um[match[1]] == 1 || um[match[1]] == 0) um[match[1]]--;
            } else {
                um[match[1]] = 0;
            }
        }
        vector<vector<int>> ans(2);
        for (auto& p : um) {
            if (p.second == 1) {
                ans[0].push_back(p.first);
            }
            if (p.second == 0) {
                ans[1].push_back(p.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};