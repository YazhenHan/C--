#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        if (matrix.size() == 1)
            row = 0;
        else
        {
            int up = 0, bottom = matrix.size() - 1;
            while (true)
            {
                if (matrix[up][0] <= target && matrix[up + 1][0] > target || matrix[up][0] > target)
                {
                    row = up;
                    break;
                }
                if (matrix[bottom][0] <= target)
                {
                    row = bottom;
                    break;
                }
                if (matrix[bottom][0] > target && matrix[bottom - 1][0] <= target)
                {
                    row = bottom - 1;
                    break;
                }
                int mid = up + (bottom - up) / 2;
                if (matrix[mid][0] > target)
                    bottom = mid;
                else if (matrix[mid][0] < target)
                    up = mid;
                else
                {
                    row = mid;
                    break;
                }
            }
        }
        int left = 0, right = matrix[row].size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if(matrix[row][mid] > target)
                right = mid - 1;
            else if(matrix[row][mid] < target)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};