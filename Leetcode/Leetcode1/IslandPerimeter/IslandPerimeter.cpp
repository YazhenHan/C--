#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    if (i - 1 >= 0 && grid[i-1][j] == 1)
                    {
                        count2++;
                    }
                    if (j + 1 < grid[i].size() && grid[i][j+1] == 1)
                    {
                        count2++;
                    }
                }
            }
        }
        return count * 4 - count2 * 2;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid =
        {{1,1}};
    cout << sol.islandPerimeter(grid) << endl;
    return 0;
}