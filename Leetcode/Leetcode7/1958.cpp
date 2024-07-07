#include <vector>

using namespace std;

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        if (rMove + 2 < 8) {
            int row = rMove + 1;
            while (row < 8) {
                if (board[row][cMove] != color && board[row][cMove] != '.')
                    row++;
                else
                    break;
            }
            if (row > rMove + 1 && row < 8 && board[row][cMove] == color)
                return true;
        }

        if (rMove - 2 >= 0) {
            int row = rMove - 1;
            while (row >= 0) {
                if (board[row][cMove] != color && board[row][cMove] != '.')
                    row--;
                else
                    break;
            }
            if (row < rMove - 1 && row >= 0 && board[row][cMove] == color)
                return true;
        }

        if (cMove + 2 < 8) {
            int col = cMove + 1;
            while (col < 8) {
                if (board[rMove][col] != color && board[rMove][col] != '.')
                    col++;
                else
                    break;
            }
            if (col > cMove + 1 && col < 8 && board[rMove][col] == color)
                return true;
        }

        if (cMove - 2 >= 0) {
            int col = cMove - 1;
            while (col >= 0) {
                if (board[rMove][col] != color && board[rMove][col] != '.')
                    col--;
                else
                    break;
            }
            if (col < cMove - 1 && col >= 0 && board[rMove][col] == color)
                return true;
        }

        if (rMove + 2 < 8 && cMove + 2 < 8) {
            int row = rMove + 1, col = cMove + 1;
            while (row < 8 && col < 8) {
                if (board[row][col] != color && board[row][col] != '.') {
                    row++;
                    col++;
                }
                else
                    break;
            }
            if (row > rMove + 1 && col > cMove + 1 && row < 8 && col < 8 && board[row][col] == color)
                return true;
        }

        if (rMove + 2 < 8 && cMove - 2 >= 0) {
            int row = rMove + 1, col = cMove - 1;
            while (row < 8 && col >= 0) {
                if (board[row][col] != color && board[row][col] != '.') {
                    row++;
                    col--;
                }
                else
                    break;
            }
            if (row > rMove + 1 && col < cMove - 1 && row < 8 && col >= 0 && board[row][col] == color)
                return true;
        }

        if (rMove - 2 >= 0 && cMove - 2 >= 0) {
            int row = rMove - 1, col = cMove - 1;
            while (row >= 0 && col >= 0) {
                if (board[row][col] != color && board[row][col] != '.') {
                    row--;
                    col--;
                }
                else
                    break;
            }
            if (row < rMove - 1 && col < cMove - 1 && row >= 0 && col >= 0 && board[row][col] == color)
                return true;
        }

        if (rMove - 2 >= 0 && cMove + 2 < 8) {
            int row = rMove - 1, col = cMove + 1;
            while (row >= 0 && col < 8) {
                if (board[row][col] != color && board[row][col] != '.') {
                    row--;
                    col++;
                }
                else
                    break;
            }
            if (row < rMove - 1 && col > cMove + 1 && row >= 0 && col < 8 && board[row][col] == color)
                return true;
        }

        return false;
    }
};