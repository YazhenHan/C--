#include <string>
#include <vector>

using namespace std;

// Out of time
class Solution {
private:
    bool isMatch(string s, string p, int i, int j) {
        if (i >= s.size() && j >= p.size()) return true;
        if (i < s.size() && j >= p.size()) return false;
        if (p[j] == '*') {
            for (int k = i; k <= s.size(); k++)
                if(isMatch(s, p, k, j + 1))
                    return true;
            return false;
        }
        if (i < s.size() && (p[j] == '?' || p[j] == s[i]))
            return isMatch(s, p, i + 1, j + 1);
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};