#include <queue>
#include <utility>

using namespace std;

class Solution {
private:
    int getS(int m) {
        int ans = 0;
        while (m != 0) {
            ans += m % 10;
            m = m / 10;
        }
        return ans;
    }
public:
    int movingCount(int m, int n, int k) {
        int ans = 1;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            auto a = q.front();
            if (a.first + 1 < m && !vis[a.first + 1][a.second] && getS(a.first + 1) + getS(a.second) <= k) {
                q.push({a.first + 1, a.second});
                vis[a.first + 1][a.second] = true;
                ans++;
            }
            if (a.second + 1 < n && !vis[a.first][a.second + 1] && getS(a.first) + getS(a.second + 1) <= k) {
                q.push({a.first, a.second + 1});
                vis[a.first][a.second + 1] = true;
                ans++;
            }
            q.pop();
        }
        return ans;
    }

    int movingCount(int m, int n, int k) {
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (getS(i) + getS(j) > k) continue;
                if (i - 1 >= 0) vis[i][j] = vis[i - 1][j] | vis[i][j];
                if (j - 1 >= 0) vis[i][j] = vis[i][j - 1] | vis[i][j];
                ans += vis[i][j];
            }
        }
        return ans;
    }
};