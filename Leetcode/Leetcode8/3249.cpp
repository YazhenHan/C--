#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> um(edges.size() + 1);
        for (const vector<int> & edge : edges) {
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);
        }
        vector<int> flags(edges.size() + 1, 1);

        int ans = 0;
        function<int(int)> dfs = [&](int cur) -> int {
            flags[cur] = 0;
            int num = 1, temp = 0;
            bool flag = true;
            for (int i : um[cur]) {
                if (flags[i]) {
                    int t = dfs(i);
                    if (temp == 0)
                        temp = t;
                    else if (temp != t)
                        flag = false;
                    num += t;
                }
            }
            if (flag) ans++;
            return num;
        };
        dfs(0);
        return ans;
    }
};