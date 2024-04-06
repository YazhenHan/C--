#include <vector>

using namespace std;

class TreeAncestor {
private:
    vector<vector<int>> parents;
public:
    TreeAncestor(int n, vector<int>& parent) {
        parents.resize(n, vector<int>(16, -1));
        for (int i = 0; i < n; i++) {
            parents[i][0] = parent[i];
        }
        for (int j = 1; j < 16; j++) {
            for (int i = 0; i < n; i++) {
                if (parents[i][j-1] != -1)
                    parents[i][j] = parents[parents[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < 16; j++) {
            if ((k >> j) & 1) {
                node = parents[node][j];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */