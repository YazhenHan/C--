#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans; 
    void dfs(int k, int n, vector<int> temp, vector<bool> & flag) {
        if (k == 0) return;
        for (int i = 1; i < 10; i++) {
            if (!flag[i] || (!temp.empty() && i <= temp.back())) {
                continue;
            }
            if (i > n) {
                return;
            }
            else if (i == n && k == 1) {
                temp.push_back(i);
                ans.push_back(temp);
                return;
            }
            else if (i < n) {
                temp.push_back(i);
                flag[i] = false;
                dfs(k - 1, n - i, temp, flag);
                flag[i] = true;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<bool> flag(10, true);
        dfs(k, n, temp, flag);
        return ans;
    }
};