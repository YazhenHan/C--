#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void dfs(string temp, vector<string> & ans, int n) {
        if (temp.size() == n) {
            ans.emplace_back(temp);
            return;
        }
        if (temp.size() == 0 || temp.back() == '1') {
            temp.push_back('0');
            dfs(temp, ans, n);
            temp.pop_back();
            temp.push_back('1');
            dfs(temp, ans,n);
        } else if (temp.size() == 0 || temp.back() == '0') {
            temp.push_back('1');
            dfs(temp, ans, n);
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        dfs("", ans, n);
        return ans;
    }
};