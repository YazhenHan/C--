#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> fa;
    vector<int> rank;
    void init(int n) {
        fa.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }
    void merge(int i, int j) {
        int x = find(i), y = find(j);    //先找到两个根节点
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto & c1, auto & c2) {
            return c1[2] < c2[2];
        });
        init(n);
        int ans = 0;
        for (auto & connection : connections) {
            if (find(connection[0]) == find(connection[1]))
                continue;
            merge(connection[0], connection[1]);
            ans += connection[2];
        }
        for (int i = 1; i < n; i++) {
            if (find(i) != find(i + 1))
                return -1;
        }
        return ans;
    }
};