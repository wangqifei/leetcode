// 36 Valid Sudoku
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int i, int j, int size)
    {
        for(int k = 0; k < size; ++k)
        {
            if(k != j && board[i][k] == board[i][j]) return false;
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, int i, int j, int size)
    {
        for(int k = 0; k < size; ++k)
        {
            if(k != i && board[k][j] == board[i][j]) return false;
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board, int i, int j, int y, int x, int size)
    {
        for(int m = 0; m < size; ++m)
        {
            for(int n = 0; n < size; ++n)
            {
                if((y+m)!=i && (x+n)!=j && board[y+m][x+n] == board[i][j]) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0) return true;
        int cols = board[0].size();
        if(cols == 0) return true;
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(board[i][j] == '.') continue;
                if(checkRow(board, i, j, 9) == false) return false;
                if(checkCol(board, i, j, 9) == false) return false;
                int x = j/3*3;
                int y = i/3*3;
                if(checkBox(board, i, j, y, x, 3) == false) return false;
            }
        }
        return true;
    }
};