#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Out of time.
class Solution {
public:
    int distinctSubseqII(string s) {
        unordered_set<string> ans;
        for (int i = 0; i < s.size(); i++) {
            string temp = s.substr(i, 1);
            auto temp2 = ans;
            for (auto c : temp2)
                if (!ans.count(c + temp))
                    ans.insert(c + temp);
            if (!temp2.count(temp))
                ans.insert(temp);
        }
        return ans.size() % 1000000007;
    }
};


class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> v(26, -1);
        vector<int> dp(s.size(), 1);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                if (v[j] != -1)
                    dp[i] = (dp[i] + dp[v[j]]) % 1000000007;
            }
            v[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i] != -1)
                ans = (ans + dp[v[i]]) % 1000000007;
        }
        return ans;
    }
};