// Unique Paths II
// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        if(h == 0) return 0;
        int w = obstacleGrid[0].size();
        vector<vector<int> > mat(h, vector<int>(w, 0));
        if(obstacleGrid[0][0] == 0) mat[0][0] = 1;  //caution!!! every entry can be 1
        for(int i = 1; i < h; ++i) {
            if(obstacleGrid[i][0] == 0) {
                mat[i][0] = mat[i-1][0];
            }
        }
        for(int i = 1; i < w; ++i) {
            if(obstacleGrid[0][i] == 0) {
                mat[0][i] = mat[0][i-1];
            }
        }
        for(int i = 1; i < h; ++i) {
            for(int j = 1; j < w; ++j) {
                if(obstacleGrid[i][j] == 0) {
                    mat[i][j] = mat[i-1][j]+mat[i][j-1];
                }
            }
        }
        return mat[h-1][w-1];
    }
};