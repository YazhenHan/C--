#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        vector<vector<int>> res;
        for (int i = 0; i < M.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < M[i].size(); j++)
            {
                int sum = M[i][j];
                int count = 1;
                if (i - 1 >= 0)
                {
                    if (j - 1 >= 0)
                    {
                        sum += M[i - 1][j - 1];
                        ++count;
                    }
                    sum += M[i - 1][j];
                    ++count;
                    if (j + 1 < M[i].size())
                    {
                        sum += M[i - 1][j + 1];
                        ++count;
                    }
                }
                if (j - 1 >= 0)
                {
                    sum += M[i][j - 1];
                    ++count;
                }
                if (j + 1 < M[i].size())
                {
                    sum += M[i][j + 1];
                    ++count;
                }
                if (i + 1 < M.size())
                {
                    if (j - 1 >= 0)
                    {
                        sum += M[i + 1][j - 1];
                        ++count;
                    }
                    sum += M[i + 1][j];
                    ++count;
                    if (j + 1 < M[i].size())
                    {
                        sum += M[i + 1][j + 1];
                        ++count;
                    }
                }
                temp.push_back(sum / count);
            }
            res.push_back(temp);
        }
        return res;
    }
};