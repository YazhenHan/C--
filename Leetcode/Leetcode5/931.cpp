#include <vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                matrix[i][j] = min(matrix[i - 1][j], min(j > 0 ? matrix[i - 1][j - 1] : INT32_MAX, j < matrix[i].size() - 1 ? matrix[i - 1][j + 1] : INT32_MAX)) + matrix[i][j];
        int ans = INT32_MAX;
        for (int j = 0; j < matrix[0].size(); j++)
            ans = min(ans, matrix[matrix.size() - 1][j]);
        return ans;
    }
};