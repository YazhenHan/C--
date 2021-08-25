#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<pair<int, int>> v; // i-th pre
        v.push_back({0, -1});
        for (int i = 0; i < v.size(); i++) {
            if (n - 1 == v[i].first) { 
                vector<int> temp;
                int t = i;
                while (t != -1) {
                    temp.push_back(v[t].first);
                    t = v[t].second;
                }
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                continue;
            }

            for (auto& a : graph[v[i].first]) {
                pair<int, int> p(a, i);
                v.push_back(p);
            }
        }
        return ans;
    }
};