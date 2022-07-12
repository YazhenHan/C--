#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> vv(m, vector<int>(n, 0));
        for (auto indice : indices) {
            for (int i = 0; i < m; i++) vv[i][indice[1]]++;
            for (int i = 0; i < n; i++) vv[indice[0]][i]++;
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (vv[i][j] % 2 != 0)
                    ans++;
        return ans;
    }
};