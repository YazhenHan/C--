#include <vector>
#include <unordered_map>

using namespace std;

class NeighborSum {
private:
    unordered_map<int, int> um1;
    unordered_map<int, int> um2;
public:
    NeighborSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int sum1 = 0, sum2 = 0;
                if (i - 1 >= 0) sum1 += grid[i - 1][j];
                if (i + 1 < grid.size()) sum1 += grid[i + 1][j];
                if (j - 1 >= 0) sum1 += grid[i][j - 1];
                if (j + 1 < grid[i].size()) sum1 += grid[i][j + 1];

                if (i - 1 >= 0 && j - 1 >= 0) sum2 += grid[i - 1][j - 1];
                if (i - 1 >= 0 && j + 1 < grid[i].size()) sum2 += grid[i - 1][j + 1];
                if (i + 1 < grid.size() && j - 1 >= 0) sum2 += grid[i + 1][j - 1];
                if (i + 1 < grid.size() && j + 1 < grid[i].size()) sum2 += grid[i + 1][j + 1];

                um1[grid[i][j]] = sum1;
                um2[grid[i][j]] = sum2;
            }
        }
    }
    
    int adjacentSum(int value) {
        return um1[value];
    }
    
    int diagonalSum(int value) {
        return um2[value];
    }
};
