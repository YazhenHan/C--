#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<string, int> um;
public:
    int minScoreTriangulation(vector<int>& values) {
        if (values.size() == 3) return values[0] * values[1] * values[2];
        int ans = INT32_MAX;
        string k;
        for (int i = 0; i < values.size(); i++) {
            k.append(to_string(values[i]) + "#");
        }
        if (um.find(k) != um.end()) return um[k];
        for (int i = 0; i <= values.size(); i++) {
            int t = values[i] * values[(i + 1) % values.size()] * values[(i + 2) % values.size()];
            vector<int> temp;
            for (int j = 0; j < values.size(); j++) {
                if (j == (i + 1) % values.size())
                    continue;
                temp.push_back(values[j]);
            }
            ans = min(ans, t + minScoreTriangulation(temp));
        }
        um[k] = ans;
        return ans;
    }
};

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT32_MAX;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
            }
        }
        return dp[0][n-1];
    }
};