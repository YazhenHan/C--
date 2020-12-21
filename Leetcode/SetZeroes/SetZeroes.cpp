#include <vector>

using namespace std;

class Solution {
private:
    void setZeroes(vector<vector<int>>& matrix, int i, int j)
    {
        for (int k = 0; k < matrix.size(); k++)
            matrix[k][j] = 0;
        for (int k = 0; k < matrix[i].size(); k++)
            matrix[i][k] = 0;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> res; 
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == 0)
                    res.push_back({i, j});
        for (auto temp : res)
            setZeroes(matrix, temp[0], temp[1]);
    }
};