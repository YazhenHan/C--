#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int j = 0; j < mat[0].size(); j++) {
            vector<int> temp;
            int i = 0, t = j;
            while (i < mat.size() && t < mat[0].size()) {
                temp.push_back(mat[i][t]);
                i++;
                t++;
            }
            sort(temp.begin(), temp.end());
            i = 0;
            t = j;
            int k = 0;
            while (i < mat.size() && t < mat[0].size()) {
                mat[i][t] = temp[k];
                i++;
                t++;
                k++;
            }
        }
        for (int i = 1; i < mat.size(); i++) {
            vector<int> temp;
            int j = 0, t = i;
            while (t < mat.size() && j < mat[0].size()) {
                temp.push_back(mat[t][j]);
                t++;
                j++;
            }
            sort(temp.begin(), temp.end());
            j = 0;
            t = i;
            int k = 0;
            while (t < mat.size() && j < mat[0].size()) {
                mat[t][j] = temp[k];
                t++;
                j++;
                k++;
            }
        }
        return mat;
    }
};