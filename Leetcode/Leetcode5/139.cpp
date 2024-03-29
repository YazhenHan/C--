#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, bool> um;
    bool dfs(string s, unordered_set<string> us) {
        if (us.count(s)) return true;
        if (um.count(s)) return um[s];
        bool ans = false;
        for (int i = 1; i < s.size(); i++)
            if (us.count(s.substr(0, i)))
                ans = ans || dfs(s.substr(i), us);
        um[s] = ans;
        return ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        return dfs(s, us);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            bool flag = false;
            for (int j = 0; j < i; j++) {
                bool temp = dp[j] && us.count(s.substr(j, i - j));
                flag = flag || temp;
            }
            dp[i] = flag;
        }
        return dp.back();
    }
};