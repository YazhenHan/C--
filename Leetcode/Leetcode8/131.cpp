#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    void dfs(const string & s, const vector<vector<int>> & palindromes, int cur, vector<string> & v) {
        if (cur == s.size()) ans.push_back(v);
        for (int i = cur; i < s.size(); i++) {
            if (palindromes[cur][i]) {
                v.push_back(s.substr(cur, i - cur + 1));
                dfs(s, palindromes, i + 1, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> palindromes(n, vector<int>(n, 1));
        palindromes[n - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                // if (j == i) palindromes[i][j] = 1;
                palindromes[i][j] = (s[i] == s[j]) && palindromes[i + 1][j - 1];
            }
        }
        vector<string> v;
        dfs(s, palindromes, 0, v);
        return ans;
    }
};