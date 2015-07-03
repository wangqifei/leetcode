// Set Matrix Zeroes Total Accepted: 36135 Total Submissions: 114561 My Submissions Question Solution 
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

// click to show follow up.

// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
#include <vector>
#include <iostream>
using namespace::std;
class Solution {
public:
    //idea is from OJ discussion, only the first column should be recorded
    void setZeroes2(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if(h == 0) return;
        int w = matrix[0].size();
        bool isColZero = false;
        for(int i = 0; i < h; ++i) {
            if(matrix[i][0] == 0) isColZero = true;
            for(int j = 1; j < w; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = h-1; i >= 0; --i) {
            for(int j = w-1; j >= 1; --j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(isColZero) matrix[i][0] = 0;
        }
    }
    //this algorithm contain too many duplicated setting to zero operations
    void setZeroes(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if(h == 0) return;
        int w = matrix[0].size();
        bool isRowZero = false;
        bool isColZero = false;
        for(int i = 0; i < h; ++i) {
            if(matrix[i][0] == 0) {
                isColZero = true;
                break;
            }
        }
        for(int i = 0; i < w; ++i) {
            if(matrix[0][i] == 0) {
                isRowZero = true;
                break;
            }
        }
        for(int i = 1; i < h; ++i) {
            for(int j = 1; j < w; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < h; ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < w; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < w; ++i) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < h; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        if(isRowZero) {
            for(int i = 0; i < w; ++i) matrix[0][i] = 0;
        }
        if(isColZero) {
            for(int i = 0; i < h; ++i) matrix[i][0] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    const int row = 5;
    const int col = 4;
    int A[row][col] = {0,0,0,5,4,3,1,4,0,1,1,4,1,2,1,3,0,0,1,1};
    vector<vector<int> > matrix(row, vector<int>(col, 0));
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            matrix[i][j] = A[i][j];
        }
    }
    Solution mySolution;
    mySolution.setZeroes(matrix);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}