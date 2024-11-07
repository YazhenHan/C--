#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < ((min(matrix.size(), matrix[0].size()) % 2 == 0) ? (min(matrix.size(), matrix[0].size()) / 2) : (min(matrix.size(), matrix[0].size()) / 2 + 1)); i++) {
            for (int j = i; j < matrix[0].size() - i; j++) {
                ans.push_back(matrix[i][j]);
            }
            for (int j = i + 1; j < matrix.size() - i; j++) {
                ans.push_back(matrix[j][matrix[0].size() - 1 - i]);
            }
            if (i != matrix.size() - 1 - i)
                for (int j = matrix[0].size() - 1 - i - 1; j >= i; j--) {
                    ans.push_back(matrix[matrix.size() - 1 - i][j]);
                }
            if (i != matrix[0].size() - 1 - i)
                for (int j = matrix.size() - 1 - i - 1; j > i; j--) {
                    ans.push_back(matrix[j][i]);
                }
        }
        return ans;
    }
};