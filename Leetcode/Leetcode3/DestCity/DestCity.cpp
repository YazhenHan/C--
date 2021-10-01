#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> um;
        for (auto&& path : paths)
            um.insert({path[0], path[1]});
        string ans = paths.front().front();
        while (um.find(ans) != um.end())
            ans = um[ans];
        return ans;
    }
};