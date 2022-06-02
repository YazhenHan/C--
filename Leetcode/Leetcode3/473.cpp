#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) return true;
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) return true;
            edges[i] -= matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        vector<int> edges(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(0, matchsticks, edges, sum / 4);
    }
};