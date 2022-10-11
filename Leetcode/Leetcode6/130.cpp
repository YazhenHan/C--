#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> flag;
    void dfs(const vector<vector<char>> & board, int i, int j) {
        if (i < 0 || i >= board.size()) return;
        if (j < 0 || j >= board[i].size()) return;
        if (board[i][j] == 'X' || flag[i][j]) return;
        flag[i][j] = true;
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        flag.resize(board.size());
        for (int i = 0; i < flag.size(); i++)
            flag[i] = vector<bool>(board[i].size(), false);
        for (int i = 0; i < board.size(); i++)
            dfs(board, i, 0);
        for (int j = 0; j < board.back().size(); j++)
            dfs(board, board.size() - 1, j);
        for (int i = board.size() - 1; i >= 0; i--)
            dfs(board, i, board.front().size() - 1);
        for (int j = board.front().size() - 1; j >= 0; j--)
            dfs(board, 0, j);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (!flag[i][j])
                    board[i][j] = 'X';
    }
};