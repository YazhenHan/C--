#include <vector>

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> r(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                r[i][preferences[i][j]] = j;
            }
        }

        for (auto&& pair : pairs) {
            r[pair[0]][pair[0]] = pair[1];
            r[pair[1]][pair[1]] = pair[0];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (r[i][j] < r[i][r[i][i]] && r[j][i] < r[j][r[j][j]]) { ans++; break; }
            }
        }
        return ans;
    }
};