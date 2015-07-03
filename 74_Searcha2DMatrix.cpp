// Search a 2D Matrix
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if(h == 0) return false;
        int w = matrix[0].size();
        int n = h*w;
        int st = 0;
        int ed = n-1;
        while(st<=ed) {
            int md = st+(ed-st)/2;
            int x = md%w;
            int y = md/w;
            if(matrix[y][x]<target) st = md+1;
            else if(matrix[y][x]>target) ed = md-1;
            else return true;
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if(h == 0) return false;
        int w = matrix[0].size();
        int row_st = 0;
        int row_ed = h-1;
        while(row_st<=row_ed) {
            int row_md = row_st+(row_ed-row_st)/2;
            if(matrix[row_md][0]>target) {
                row_ed = row_md-1;
            }
            else if(matrix[row_md][0]<target) {
                row_st = row_md+1;
            }
            else return true;
        }
        int row = row_ed;
        if(row < 0) return false;
        int col_st = 0;
        int col_ed = w-1;
        while(col_st<=col_ed) {
            int col_md = col_st+(col_ed-col_st)/2;
            if(matrix[row][col_md]>target) {
                col_ed = col_md-1;
            }
            else if(matrix[row][col_md]<target) {
                col_st = col_md+1;
            }
            else return true;
        }
        return false;
    }
};