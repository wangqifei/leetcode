// Word Search
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

class Solution {
public:
    bool dfs(vector<vector<char> > & board, string word, int i, int j, int k) {
        if(k == word.size()) return true;
        int h = board.size();
        int w = board[0].size();
        char ch = board[i][j];
        board[i][j] = '#'; //Caution!!! use # to denote this point has been visited. Otherwise, we cannot prevent the back and forth visiting
        if(i < h-1 && board[i+1][j] == word[k] && dfs(board, word, i+1, j, k+1)) return true;
        if(i > 0 && board[i-1][j] == word[k] && dfs(board, word, i-1, j, k+1)) return true;
        if(j < w-1 && board[i][j+1] == word[k] && dfs(board, word, i, j+1, k+1)) return true;
        if(j > 0 && board[i][j-1] == word[k] && dfs(board, word, i, j-1, k+1)) return true;
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return word.empty();
        if(word.empty()) return true;
        int h = board.size();
        int w = board[0].size();
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 1))
                    return true;
            }
        }
        return false;
    }
};