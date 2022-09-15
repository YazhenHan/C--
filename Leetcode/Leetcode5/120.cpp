#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] = min(j > 0 ? triangle[i - 1][j - 1] : INT32_MAX, j == triangle[i].size() - 1 ? INT32_MAX : triangle[i - 1][j]) + triangle[i][j];
            }
        }
        int ans = INT32_MAX;
        for (int j = 0; j < triangle[triangle.size() - 1].size(); j++) {
            ans = min(ans, triangle[triangle.size() - 1][j]);
        }
        return ans;
    }
};