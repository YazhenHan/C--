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
    // BFS
    int findCheapestPrice3(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = INT32_MAX;
        vector<vector<pair<int, int>>> adjust(n); // i-th to i-j-th cost
        for (auto& flight : flights)
            adjust[flight[0]].push_back({ flight[1], flight[2] });
        vector<tuple<int, int, int, int>> v; // i-th cost depth pre
        tuple<int, int, int, int> s(src, 0, -1, -1);
        v.push_back(s);
        for (int i = 0; i < v.size(); i++) {
            if (dst == get<0>(v[i])) { ans = min(ans, get<1>(v[i])); continue; }
            if (k == get<2>(v[i])) continue;

            for (auto& a : adjust[get<0>(v[i])]) {
                bool flag = false;
                int t = i;
                while (t != -1) {
                    if (a.first == get<0>(v[t])) flag = true;
                    t = get<3>(v[t]);
                }
                if (flag) continue;

                tuple<int, int, int, int> tt(a.first, a.second + get<1>(v[i]), 1 + get<2>(v[i]), i);
                v.push_back(tt);
            }
        }
        if (ans == INT32_MAX) ans = -1;
        return ans;
    }

    // DFS
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

private:
    static constexpr int INF = 10000 * 101 + 1;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> f(k + 2, vector<int>(n, INF));
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t)
            for (auto&& flight : flights)
                f[t][flight[1]] = min(f[t][flight[1]], f[t - 1][flight[0]] + flight[2]);
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t)
            ans = min(ans, f[t][dst]);
        return ans == INF ? -1 : ans;
    }
};