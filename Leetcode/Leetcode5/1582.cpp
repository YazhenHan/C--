#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        vector<vector<int>> mat1 = mat;
        for (int i = 0; i < mat.size(); i++) {
            int temp = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                temp += mat[i][j];
            }
            mat1[i] = vector<int>(mat[0].size(), temp);
        }
        vector<vector<int>> mat2 = mat;
        for (int i = 0; i < mat[0].size(); i++) {
            int temp = 0;
            for (int j = 0; j < mat.size(); j++) {
                temp += mat[j][i];
            }
            if (temp == 1) {
                for (int j = 0; j < mat.size(); j++) {
                    if (mat1[j][i] == 1 && mat[j][i] == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};