#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int dfs(const unordered_set<string> & us, const string & target, unordered_map<string, int> & um) {
        if (um.count(target)) return um[target];
        int ans = INT32_MAX;
        for (int i = 1; i <= target.size(); i++) {
            if (us.count(target.substr(0, i))) {
                int temp = dfs(us, target.substr(i), um);
                if (temp != INT32_MAX)
                    ans = min(ans, 1 + temp);
            }
        }
        um[target] = ans;
        return ans;
    }
public:
    int minValidStrings(vector<string>& words, string target) {
        unordered_set<string> us;
        for (const string & word : words) {
            for (int i = 0; i <= word.size(); i++) {
                us.insert(word.substr(0, i));
            }
        }

        // dynamic programming
        /*
        vector<vector<int>> dp(target.size(), vector<int>(target.size(), -1));
        for (int skip = 1; skip <= target.size(); skip++) {
            for (int i = 0; i + skip <= target.size(); i++) {
                if (us.count(target.substr(i, skip))) {
                    dp[i][i + skip - 1] = 1;
                    continue;
                }
                int ans = INT32_MAX;
                for (int j = 1; j < skip; j++) {
                    if (dp[i][i + j - 1] != -1 && dp[i + j][i + skip - 1] != -1) {
                        ans = min(ans, dp[i][i + j - 1] + dp[i + j][i + skip - 1]);
                    }
                }
                if (ans != INT32_MAX) dp[i][i + skip - 1] = ans;
            }
        }

        return dp[0][target.size() - 1];
        */

        // dfs + filter
        /*
        unordered_map<string, int> um;
        um.insert({"", 0});
        int ans = dfs(us, target, um);
        if (ans == INT32_MAX) return -1;
        return ans;
        */
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        auto prefix_function = [](const string& word, const string& target) -> vector<int> {
            string s = word + '#' + target;
            int n = s.size();
            vector<int> pi(n, 0);
            for (int i = 1; i < n; i++) {
                int j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1];
                }
                if (s[i] == s[j]) {
                    j++;
                }
                pi[i] = j;
            }
            return pi;
        };

        int n = target.size();
        vector<int> back(n, 0);
        for (const string& word : words) {
            vector<int> pi = prefix_function(word, target);
            int m = word.size();
            for (int i = 0; i < n; i++) {
                back[i] = max(back[i], pi[m + 1 + i]);
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i] = 1e9;
        }
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i + 1 - back[i]] + 1;
            if (dp[i + 1] > n) {
                return -1;
            }
        }
        return dp[n];
    }
};