#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 0)
                continue;
            else if (colsum[i] == 1) {
                if (upper == 0 && lower == 0)
                    return vector<vector<int>>();
                if (upper >= lower) {
                    ans[0][i] = 1;
                    upper--;
                }
                else {
                    ans[1][i] = 1;
                    lower--;
                }
            }
            else if (colsum[i] == 2) {
                if (upper == 0 || lower == 0)
                    return vector<vector<int>>();
                ans[0][i] = 1;
                upper--;
                ans[1][i] = 1;
                lower--;
            }
        }
        if (upper == 0 && lower == 0)
            return ans;
        else
            return vector<vector<int>>();
    }
};