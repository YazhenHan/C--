#include <vector>
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
    void union2(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }

    void dfs(const vector<vector<int>>& isConnected, vector<bool> & filter, int i) {
        if (filter[i]) return;
        filter[i] = true;
        for (int j = 0; j < isConnected[i].size(); j++) {
            if (isConnected[i][j])
                dfs(isConnected, filter, j);
        }
    }
public:
    // Union Find
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        id.resize(isConnected.size());
        sz.resize(isConnected.size());
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        count = N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j++)
                if (isConnected[i][j])
                    union2(i, j);
        return count;
    }

    // DFS
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<bool> filter(N, false);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!filter[i]) {
                filter[i] = true;
                ans++;
                dfs(isConnected, filter, i);
            }
        }
    }

    // BFS
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<bool> filter(N, false);
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (filter[i]) continue;
            ans++;
            q.push(i);
            while (!q.empty()) {
                int t = q.front();
                for (int j = 0; j < N; j++) {
                    if (!filter[j] && isConnected[t][j]) {
                        q.push(j);
                        filter[j] = true;
                    }
                }
                q.pop();
            }
        }
        return ans;
    }
};