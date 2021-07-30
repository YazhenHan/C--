#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            int flag[9] = { 0 };
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                    if (flag[board[i][j] - '1'] > 0)
                        return false;
                    else
                        flag[board[i][j] - '1']++;
            }            
        }
        
        for (int j = 0; j < 9; j++)
        {
            int flag[9] = { 0 };
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                    if (flag[board[i][j] - '1'] > 0)
                        return false;
                    else
                        flag[board[i][j] - '1']++;
            }
        }
        
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                int flag[9] = { 0 };
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (board[i + k][j + l] != '.')
                            if (flag[board[i + k][j + l] - '1'] > 0)
                                return false;
                            else
                                flag[board[i + k][j + l] - '1']++;
                    }
                    cout << endl;
                }
            }
        }
        
        return true;
    }
};