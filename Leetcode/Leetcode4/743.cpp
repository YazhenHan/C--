#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> vv(n);
        for (auto & time : times)
            vv[time[0] - 1].push_back({time[1] - 1, time[2]});

        vector<int> distTo(n);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
            distTo[i] = INT32_MAX;
        distTo[k - 1] = 0;
        pq.push(k - 1);
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            for (auto e : vv[v]) {
                int w = e.first;
                if (distTo[w] > distTo[v] + e.second) {
                    distTo[w] = distTo[v] + e.second;
                    pq.push(w);
                }
            }
        }
        int ans = 0;
        for (auto& d : distTo) ans = max(ans, d);
        return ans == INT32_MAX ? -1 : ans;
    }
};