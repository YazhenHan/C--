#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) bottom = mid - 1;
            else top = mid + 1;
        }
        if (bottom < 0) return false;
        int left = 0, right = matrix[bottom].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[bottom][mid] == target) return true;
            else if (matrix[bottom][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};