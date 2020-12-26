#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> flag(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    flag[i][j] = (j == 0 ? 0 : flag[i][j-1]) + 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int width = flag[i][j];
                for (int k = i; k >= 0; k--)
                {
                    width = min(width, flag[k][j]);
                    ans = max(width * (i - k + 1), ans);
                }
            }
        }
        
        return ans;
    }
};