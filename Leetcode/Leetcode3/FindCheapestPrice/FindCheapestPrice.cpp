#include <vector>
#include <utility>
#include <tuple>
#include <iostream>

using namespace std;

class Solution {
private:
    void dfs(const vector<vector<pair<int, int>>>& adjust, int src, int dst, int k, int& ans, vector<bool> flags, int cost) {
        if (src == dst) {
            ans = min(ans, cost);
            return;
        }
        if (k < 0 || cost > ans) return;
        for (auto& a : adjust[src]) {
            if (flags[a.first])
                continue;
            vector<bool> t = flags;
            t[a.first] = true;
            dfs(adjust, a.first, dst, k - 1, ans, t, cost + a.second);
        }
    }
public:
    int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjust(n);
        for (auto& flight : flights)
            adjust[flight[0]].push_back({ flight[1], flight[2] });
        vector<bool> flags(n, false);
        flags[src] = true;
        int ans = INT32_MAX;
        dfs(adjust, src, dst, k, ans, flags, 0);
        if (ans == INT32_MAX) ans = -1;
        return ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> edgeTo(n);
        edgeTo[src] = -1;

        int ans = INT32_MAX;

        vector<int> distTo(n, INT32_MAX);
        distTo[src] = 0;

        vector<vector<pair<int, int>>> adjust(n);
        for (auto& flight : flights)
            adjust[flight[0]].push_back({ flight[1], flight[2] });

        for (int i = 0; i < adjust.size(); i++) {
            for (auto& a : adjust[i]) {
                if (distTo[a.first] == INT32_MAX || distTo[a.first] > distTo[i] + a.second) {
                    distTo[a.first] = distTo[i] + a.second;
                }
            }
        }

        return ans;
    }
};