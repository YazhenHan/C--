#include <vector>
#include <functional>

using namespace std;

class Solution {
private:
    vector<vector<pair<int, int>>> vvp;
    int temp = 0;
    void dfs(int root, int cur, int signalSpeed, vector<bool> & flags) {
        flags[root] = false;
        if (cur % signalSpeed == 0) {
            temp++;
        }
        for (auto& v : vvp[root]) {
            if (flags[v.first])
                dfs(v.first, cur + v.second, signalSpeed, flags);
        }
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        vvp.resize(edges.size() + 1);
        for (auto& edge : edges) {
            vvp[edge[0]].emplace_back(edge[1], edge[2]);
            vvp[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<int> ans(edges.size() + 1, 0);
        for (int i = 0; i < edges.size() + 1; i++) {
            vector<int> vi;
            vector<bool> flags(edges.size() + 1, true);
            flags[i] = false;
            for (auto& v : vvp[i]) {
                temp = 0;
                dfs(v.first, v.second, signalSpeed, flags);
                for (auto& j : vi) {
                    ans[i] += temp * j;
                }
                vi.emplace_back(temp);
            }
        }
        return ans;
    }
};