#include <vector>

using namespace std;

class Solution {
private:
    int find(int x, vector<int>& nodes) {
        return nodes[x] == x ? x : nodes[x] = find(nodes[x], nodes);
    }

    void unite(int x, int y, vector<int>& nodes) {
        nodes[find(x, nodes)] = find(y, nodes);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> nodes(edges.size() + 1, 0);
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i] = i;
        }

        for (const auto & edge : edges) {
            if (find(edge[0], nodes) == find(edge[1], nodes)) {
                return edge;
            }
            unite(edge[0], edge[1], nodes);
        }

        return {0, 0};
    }
};