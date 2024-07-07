#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix.front().size(); j++) {
            int temp = -1;
            for (int i = 0; i < matrix.size(); i++) {
                temp = max(temp, matrix[i][j]);
            }
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = temp;
            }
        }
        return matrix;
    }
};