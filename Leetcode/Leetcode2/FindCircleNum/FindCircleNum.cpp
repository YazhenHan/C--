#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> filter;
    void dfs(vector<vector<int>>& isConnected, int n) {
        if (filter[n])
        {
            return;
        }
        filter[n] = true;
        for (int i = 0; i < isConnected[n].size(); i++)
            if (isConnected[n][i] == 1)
                dfs(isConnected, i);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        filter.resize(N);
        for (auto f : filter)
            f = false;
        int res = 0;
        for (int i = 0; i < N; i++)
            if (!filter[i])
            {
                res++;
                dfs(isConnected, i);
            }
        return res;
    }
};