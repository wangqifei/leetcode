// 130 Surrounded Regions
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

class Solution {
public:
    //Caution!!! no need to consider the peripheral border, so the condition
        // is i > 1, i < rows - 2, not i > 0, i < rows - 1.
        //
        // if use i > 0, i < rows - 1, DFS solution will get a Runtime Error, confusing!
    void dfs(vector<vector<char> >& board, vector<vector<bool> >& mask, int i, int j, int h, int w) {
        if(i > 1 && mask[i-1][j] == false && board[i-1][j] == 'O') {
            mask[i-1][j] = true;
            dfs(board, mask, i-1, j, h, w);
        }
        if(i < h-2 && mask[i+1][j] == false && board[i+1][j] == 'O') {
            mask[i+1][j] = true;
            dfs(board, mask, i+1, j, h, w);
        }
        if(j > 1 && mask[i][j-1] == false && board[i][j-1] == 'O') {
            mask[i][j-1] = true;
            dfs(board, mask, i, j-1, h, w);
        }
        if(j < w-2 && mask[i][j+1] == false && board[i][j+1] == 'O') {
            mask[i][j+1] = true;
            dfs(board, mask, i, j+1, h, w);
        }
    }
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if(h == 0) return;
        int w = board[0].size();
        vector<vector<bool> > mask(h, vector<bool>(w, false));
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                    if(mask[i][j] == false && board[i][j] == 'O') {
                        mask[i][j] = true;
                        dfs(board, mask, i, j, h, w);
                    }
                }
            }
        }
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(mask[i][j] == false && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};