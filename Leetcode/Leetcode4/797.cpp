#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& v) {
        int t = v.back();
        if (t == graph.size() - 1) {
            ans.push_back(v);
            return;
        }
        for (auto t : graph[t]) {
            v.push_back(t);
            dfs(graph, ans, v);
            v.pop_back();
        }
    }

    void bfs(const vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& v) {
        int t = v.back();
    }
public:
    // dfs
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(0);
        dfs(graph, ans, v);
        return ans;
    }

    // bfs
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        vector<int> p;
        p.push_back(0);
        q.push(p);
        while (!q.empty()) {
            auto t = q.front();
            for (auto g : graph[t.back()]) {
                vector<int> tp = t;
                tp.push_back(g);
                if (g == graph.size() - 1)
                    ans.push_back(tp);
                else
                    q.push(tp);
            }
        }
        return ans;
    }
    // bfs
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