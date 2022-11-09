#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp1(n, vector<int>(n, n));
        vector<vector<int>> dp2(n, vector<int>(n, n));
        vector<vector<int>> dp3(n, vector<int>(n, n));
        vector<vector<int>> dp4(n, vector<int>(n, n));
        unordered_set<string> banned;
        for (auto &&vec : mines)
            banned.emplace(to_string(vec[0]) + "#" + to_string(vec[1]));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (banned.count(to_string(i) + "#" + to_string(j)))
                    dp1[i][j] = min(dp1[i][j], 0);
                else if (j == 0)
                    dp1[i][j] = min(dp1[i][j], 1);
                else
                    dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(to_string(i) + "#" + to_string(j)))
                    dp2[i][j] = min(dp2[i][j], 0);
                else if (j == n - 1)
                    dp2[i][j] = min(dp2[i][j], 1);
                else
                    dp2[i][j] = min(dp2[i][j], dp2[i][j + 1] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (banned.count(to_string(i) + "#" + to_string(j)))
                    dp3[i][j] = min(dp3[i][j], 0);
                else if (i == 0)
                    dp3[i][j] = min(dp3[i][j], 1);
                else
                    dp3[i][j] = min(dp3[i][j], dp3[i - 1][j] + 1);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (banned.count(to_string(i) + "#" + to_string(j)))
                    dp4[i][j] = min(dp4[i][j], 0);
                else if (i == n - 1)
                    dp4[i][j] = min(dp4[i][j], 1);
                else
                    dp4[i][j] = min(dp4[i][j], dp4[i + 1][j] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, min(dp1[i][j], min(dp2[i][j], min(dp3[i][j], dp4[i][j]))));
        return ans;
    }
};