#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> vv(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int ans = 0;
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    vv[i][j] = max(vv[i - 1][j - 1] + 1, max(vv[i - 1][j], vv[i][j - 1]));
                } else {
                    vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]);
                }
                ans = max(ans, vv[i][j]);
            }
        }
        return ans;
    }
};