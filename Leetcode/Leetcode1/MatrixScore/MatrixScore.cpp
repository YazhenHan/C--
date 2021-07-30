#include <vector>

using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i][0] == 0)
            {
                for (int j = 0; j < A[i].size(); j++)
                {
                    A[i][j] = A[i][j] == 0 ? 1 : 0;
                }
            }
        }

        for (int i = 1; i < A[0].size(); i++)
        {
            int count = 0;
            for (int j = 0; j < A.size(); j++)
            {
                if (A[j][i] == 1)
                {
                    count++;
                }
            }
            if (count <= A.size() / 2)
            {
                for (int j = 0; j < A.size(); j++)
                {
                    A[j][i] = A[j][i] == 0 ? 1 : 0;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int temp = 1;
            for (int j = A[i].size() - 1; j >= 0; j--)
            {
                res += A[i][j] * temp;
                temp *= 2;
            }   
        }
        return res;
    }
};