#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> flags(n, true);
        unordered_map<int, vector<int>> um;
        for (auto& edge : edges) {
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);
        }

        long long ans = 0, forAns = 0;
        for (int i = 0; i < n; i++) {
            if (!flags[i]) continue;
            queue<int> q;
            q.push(i);
            flags[i] = false;
            int temp = 1;
            while (!q.empty()) {
                int t = q.front();
                for (auto j : um[t]) {
                    if (flags[j]) {
                        q.push(j);
                        flags[j] = false;
                        temp++;
                    }
                }
                q.pop();
            }
            ans += temp * forAns;
            forAns += temp;
        }
        return ans;
    }
};