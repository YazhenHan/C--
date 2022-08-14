#include <vector>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long> nodes(edges.size(), 0);
        for (int i = 0; i < edges.size(); i++)
            nodes[edges[i]] += i;
        long temp = 0;
        int ans = 0;
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i] > temp) {
                ans = i;
                temp = nodes[i];
            }
        return ans;
    }
};