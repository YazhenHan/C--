#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> forRes;
        forRes.resize(m);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp;
            temp.resize(n);
            forRes.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    forRes[i][j] = 1;
                    continue;
                }
                if (j == 0)
                {
                    forRes[i][j] = 1;
                    continue;
                }
                forRes[i][j] = forRes[i - 1][j] + forRes[i][j-1];
            }
            
        }
        return forRes[m-1][n-1];
    }
};