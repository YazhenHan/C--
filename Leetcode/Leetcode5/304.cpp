#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> vv;
    int get(const vector<vector<int>>& vv, int i, int j) {
        int m = vv.size() - 1, n = vv.front().size() - 1;
        i = max(0, min(i, m));
        j = max(0, min(j, n));
        return vv[i][j];
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        vv = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1] + matrix[i - 1][j - 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get(vv, row2 + 1, col2 + 1) - get(vv, row1, col2 + 1) - get(vv, row2 + 1, col1) + get(vv, row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */