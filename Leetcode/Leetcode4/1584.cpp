#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> id;
    vector<int> sz;
    int count;

    int find(int p) {
        if (p == id[p]) return p;
        return id[p] = find(id[p]);
    }
    bool union2(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return false;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
        return true;
    }

    struct Edge {
        int len, i, j;
        Edge(int len, int i, int j) : len(len), i(i), j(j) {}
        
        friend bool operator < (const Edge & a, const Edge & b) { return a.len > b.len; }
    };
public:
    // Kruskal
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        vector<Edge> vv;
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
                vv.emplace_back(abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]), i, j);
        sort(vv.begin(), vv.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });

        int ans = 0, edge = 0, i = 0;
        int N = points.size();
        id.resize(N);
        sz.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        count = N;
        while (edge < N - 1) {
            if (union2(vv[i].i, vv[i].j)) {
                ans += vv[i].len;
                edge++;
            }
            i++;
        }
        return ans;
    }

    // Prim
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        vector<vector<Edge>> vv(points.size());
        for (int i = 0; i < points.size(); i++)
            for (int j = 0; j < points.size(); j++)
                vv[i].emplace_back(abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]), i, j);

        int ans = 0;
        priority_queue<Edge> pq;
        vector<bool> marked(points.size(), false);
        marked[0] = true;
        for (Edge e : vv[0])
            if (!marked[e.j])
                pq.push(e);
        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();
            if (marked[e.i] && marked[e.j]) continue;
            ans += e.len;
            if (!marked[e.i]) {
                marked[e.i] = true;
                for (Edge e : vv[e.i])
                    if (!marked[e.j])
                        pq.push(e);
            }
            if (!marked[e.j]) {
                marked[e.j] = true;
                for (Edge e : vv[e.j])
                    if (!marked[e.j])
                        pq.push(e);
            }
        }
        return ans;
    }
};