#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> temp;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int t1 = i - 1 >= 0 ? matrix[i - 1][j] : 0;
                int t2 = j - 1 >= 0 ? matrix[i][j - 1] : 0;
                int t3 = i - 1 >= 0 &&  j - 1 >= 0 ? matrix[i - 1][j - 1] : 0;
                matrix[i][j] = t1 ^ t2 ^ t3 ^ matrix[i][j];
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[temp.size() - k];
    }
};