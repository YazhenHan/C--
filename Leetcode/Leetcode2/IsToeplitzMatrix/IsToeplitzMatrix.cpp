#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i + 1, k = 1; j < matrix.size() && k < matrix[j].size(); j++, k++)
                if (matrix[j][k] != matrix[i][0])
                    return false;
        for (int i = 0; i < matrix[0].size(); i++)
            for (int j = 1, k = i + 1; j < matrix.size() && k < matrix[j].size(); j++, k++)
                if (matrix[j][k] != matrix[0][i])
                    return false;
        return true;
    }
};