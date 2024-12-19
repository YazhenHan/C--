#include <vector>
#include <string>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<pair<int, int>>> vvp;
    void dfs(vector<pair<int, int>> & vp, const int n) {
        if (vp.size() == n) {
            vvp.push_back(vp);
            return;
        }

        unordered_set<int> us1, us2, us3;
        for (const pair<int, int> & p : vp) {
            us1.insert(p.second);
            us2.insert(p.first + p.second);
            us3.insert(p.first - p.second);
        }
        for (int i = 0; i < n; i++) {
            if (us1.count(i) || us2.count(vp.size() + i) || us3.count(vp.size() - i)) continue;
            vp.push_back({vp.size(), i});
            dfs(vp, n);
            vp.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int, int>> vp;
        dfs(vp, n);
        vector<vector<string>> ans;
        for (const vector<pair<int, int>> & vp : vvp) {
            vector<string> vs(n, string(n, '.'));
            for (const pair<int, int> & p : vp) {
                vs[p.first][p.second] = 'Q';
            }
            ans.push_back(vs);
        }
        return ans;
    }
};