#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++)
        {
            int N = A[i].size();
            for (int j = 0; j < N; j++)
                A[i][j] = 1 - A[i][j];
            for (int j = 0; j < N / 2; j++)
            {
                int temp = A[i][j];
                A[i][j] = A[i][N - 1 - j];
                A[i][N - 1 - j] = temp;
            }
        }
        return A;
    }
};