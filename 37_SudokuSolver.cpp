37 Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


class Solution {
public:
    bool check(vector<vector<char> >& board, int y, int x, char val)
    {
        for(int k = 0; k < 9; ++k)
        {
            if(board[y][k] == val) return false;
            if(board[k][x] == val) return false;
        }
        int i = y/3*3;
        int j = x/3*3;
        for(int m = 0; m < 3; ++m)
        {
            for(int n = 0; n < 3; ++n)
            {
                if(board[m+i][n+j] == val) return false;
            }
        }
        return true;
    }
    void go(vector<vector<char> >& board, int cur, bool& finished)
    {
        if(cur == 81)
        {   
            finished = true;
            return;
        }
        int y = cur/9;
        int x = cur%9;
        if(board[y][x] != '.')
        {
            go(board, cur+1, finished);
        }
        else
        {
            for(int i = 1; i <= 9; ++i)
            {
                if(check(board, y, x, i+'0'))
                {
                    board[y][x] = i+'0';
                    go(board, cur+1, finished);
                    if(finished) return;
                    else board[y][x] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool finished = false;
        go(board, 0, finished);
    }
};