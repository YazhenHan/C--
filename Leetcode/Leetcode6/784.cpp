#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<string> ans;
    void dfs(string & s, int i) {
        for (int j = i; j < s.size(); j++) {
            if (isalpha(s[j])) {
                s[i] = toupper(s[i]);
                ans.insert(s);
                dfs(s, i + 1);
                s[i] = tolower(s[i]);
                ans.insert(s);
                dfs(s, i + 1);
                break;
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        ans.insert(s);
        dfs(s, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};