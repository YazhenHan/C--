#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> matrix2;
    vector<vector<int>> matrix3;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        matrix3 = matrix;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            vector<int> tempV;
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                int tempB = j == 0 ? 0 : tempV[j - 1];
                tempV.push_back(tempB + matrix[i][j]);
            }
            matrix2.push_back(tempV);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (size_t i = row1; i <= row2; i++)
            ans += matrix2[i][col2] - matrix2[i][col1] + matrix3[i][col1];
        return ans;
    }
};