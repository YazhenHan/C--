#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    vector<int> ans;
    void forAns(vector<vector<int>>& matrix, int k) {
        for (int j = k; j <= n - k - 1; j++)
            ans.push_back(matrix[k][j]);
        for (int i = k + 1; i <= m - k - 1; i++)
            ans.push_back(matrix[i][n - k - 1]);
        for (int j = n - k - 2; m - k - 1 != k && j >= k; j--)
            ans.push_back(matrix[m - k - 1][j]);
        for (int i = m - k - 2; k != n - k - 1 && i > k; i--)
            ans.push_back(matrix[i][k]);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        m = matrix.size();
        n = matrix[0].size();
        for (int i = 0; i <= min(ceil(m / 2.0 - 1), ceil(n / 2.0 - 1)); i++)
            forAns(matrix, i);
        return ans;
    }
};