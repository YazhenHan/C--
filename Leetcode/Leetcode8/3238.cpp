#include <vector>

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> vv(n, vector<int>(11, 0));
        vector<int> v(n, 0);
        int ans = 0;
        for (const vector<int> & p : pick) {
            if (v[p[0]] == -1) continue;
            vv[p[0]][p[1]]++;
            v[p[0]] = max(v[p[0]], vv[p[0]][p[1]]);
            if (v[p[0]] > p[0]) {
                ans++;
                v[p[0]] = -1;
            }
        }
        return ans;
    }
};