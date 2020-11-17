#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        bool filter[R][C]{false};
        vector<vector<int>> res;
        res.push_back({r0, c0});
        filter[r0][c0] = true;
        for (int i = 0; i < res.size(); i++)
        {
            vector<int> temp = res[i];
            if (temp[0] + 1 < R && !filter[temp[0] + 1][temp[1]])
            {
                res.push_back({temp[0] + 1, temp[1]});
                filter[temp[0] + 1][temp[1]] = true;
            }
            if (temp[0] - 1 >= 0 && !filter[temp[0] - 1][temp[1]])
            {
                res.push_back({temp[0] - 1, temp[1]});
                filter[temp[0] - 1][temp[1]] = true;
            }
            if (temp[1] + 1 < C && !filter[temp[0]][temp[1] + 1])
            {
                res.push_back({temp[0], temp[1] + 1});
                filter[temp[0]][temp[1] + 1] = true;
            }
            if (temp[1] - 1 >= 0 && !filter[temp[0]][temp[1] - 1])
            {
                res.push_back({temp[0], temp[1] - 1});
                filter[temp[0]][temp[1] - 1] = true;
            }
        }
        return res;
    }
};

int main()
{
}