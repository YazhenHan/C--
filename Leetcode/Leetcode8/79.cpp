#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        function<bool(int, int, int, vector<vector<int>>&)> dfs = [&](int i, int j, int cur, vector<vector<int>> & flags) -> bool {
            if (cur == word.size()) return true;
            bool ans = false;
            if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && flags[i][j] && board[i][j] == word[cur]) {
                flags[i][j] = 0;
                ans |= dfs(i + 1, j, cur + 1, flags);
                ans |= dfs(i - 1, j, cur + 1, flags);
                ans |= dfs(i, j + 1, cur + 1, flags);
                ans |= dfs(i, j - 1, cur + 1, flags);
                flags[i][j] = 1;
            }
            return ans;
        };

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<int>> flags(board.size(), vector<int>(board[i].size(), 1));
                if (dfs(i, j, 0, flags)) return true;
            }
        }
        return false;
    }
};