#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int m, int n, vector<vector<bool>>& flags) {
        if (!flags[m][n] || board[m][n] == '.') return;
        flags[m][n] = false;
        if (m + 1 < board.size()) dfs(board, m + 1, n, flags);
        if (m - 1 >= 0) dfs(board, m - 1, n, flags);
        if (n + 1 < board[0].size()) dfs(board, m, n + 1, flags);
        if (n - 1 >= 0) dfs(board, m, n - 1, flags);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<bool>> flags(board.size(), vector<bool>(board[0].size(), true));
        int ans = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X' && flags[i][j]) {
                    ans++;
                    dfs(board, i, j, flags);
                }
            }
        }
        return ans;
    }
};