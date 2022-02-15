#include <vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> a(matrix.size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            int t = matrix[i][0];
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < t) {
                    a[i] = j;
                    t = matrix[i][j];
                }
            }
        }
        for (int j = 0; j < a.size(); j++) {
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][a[j]] > matrix[j][a[j]]) {
                    a[j] = -1;
                    break;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != -1) {
                ans.push_back(matrix[i][a[i]]);
            }
        }
        return ans;
    }
};