#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    string ss[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(const string & digits, string & s) {
        if (s.size() == digits.size()) ans.push_back(s);
        else
        for (auto c : ss[digits[s.size()] - '2']) {
            s.push_back(c);
            dfs(digits, s);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        string s = "";
        dfs(digits, s);
        return ans;
    }
};