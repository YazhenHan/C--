#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> ans;
    void dfs(int n, string & s, int left, int right) {
        if (s.size() / 2 == n) ans.push_back(s);
        else
        if (left == right) {
            s.push_back('(');
            dfs(n, s, left + 1, right);
            s.pop_back();
        } else {
            if (left < n) {
                s.push_back('(');
                dfs(n, s, left + 1, right);
                s.pop_back();
            }
            s.push_back(')');
            dfs(n, s, left, right + 1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(n, s, 0, 0);
        return ans;
    }
};