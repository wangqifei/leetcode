// 64 Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        if(h == 0) return 0;
        int w = grid[0].size();
        vector<vector<int> > mat(grid);
        mat[0][0] = grid[0][0];
        for(int i = 1; i < h; ++i) {
            mat[i][0] = mat[i-1][0]+grid[i][0];
        }
        for(int i = 1; i < w; ++i) {
            mat[0][i] = mat[0][i-1]+grid[0][i];
        }
        for(int i = 1; i < h; ++i) {
            for(int j = 1; j < w; ++j) {
                mat[i][j] = min(mat[i-1][j], mat[i][j-1])+grid[i][j];
            }
        }
        return mat[h-1][w-1];
    }
};