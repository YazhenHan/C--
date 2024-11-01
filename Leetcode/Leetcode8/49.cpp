#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strs2 = strs;
        for (string & str : strs2) {
            sort(str.begin(), str.end());
        }
        unordered_map<string, int> um;
        vector<vector<string>> ans;
        for (int i = 0; i < strs2.size(); i++) {
            if (!um.count(strs2[i])) {
                ans.push_back({strs[i]});
                um[strs2[i]] = ans.size() - 1;
            } else {
                ans[um[strs2[i]]].push_back(strs[i]);
            }
        }
        return ans;
    }
};