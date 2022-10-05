#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans = board;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                int temp = 0;
                if (i - 1 >= 0 && j - 1 >= 0) temp += board[i - 1][j - 1];
                if (i - 1 >= 0) temp += board[i - 1][j];
                if (i - 1 >= 0 && j + 1 < ans[i].size()) temp += board[i - 1][j + 1];
                if (j - 1 >= 0) temp += board[i][j - 1];
                if (j + 1 < ans[i].size()) temp += board[i][j + 1];
                if (i + 1 < ans.size() && j - 1 >= 0) temp += board[i + 1][j - 1];
                if (i + 1 < ans.size()) temp += board[i + 1][j];
                if (i + 1 < ans.size() && j + 1 < ans[i].size()) temp += board[i + 1][j + 1];
                if (temp < 2 || temp > 3) ans[i][j] = 0;
                if (temp == 3) ans[i][j] = 1;
            }
        }
        board = ans;
    }
};