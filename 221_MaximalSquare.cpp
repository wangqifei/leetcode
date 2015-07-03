// 221 Maximal Square Total Accepted: 4962 Total Submissions: 24474 My Submissions Question Solution 
// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

// For example, given the following matrix:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.
// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.

// Hide Tags Dynamic Programming


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h == 0) return 0;
        int w = matrix[0].size();
        int len = 0;
        vector<vector<int> > mat(h, vector<int>(w, 0));
        for(int i = 0; i < h; ++i) {
            mat[i][0] = matrix[i][0] - '0';
            if(mat[i][0]>len) len = mat[i][0];
        }
        for(int i = 0; i < w; ++i) {
            mat[0][i] = matrix[0][i] - '0';
            if(mat[0][i]>len) len = mat[0][i];
        }
        for(int i = 1; i < h; ++i) {
            for(int j = 1; j < w; ++j) {
                if(matrix[i][j] == '1') {
                    mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1]))+1;
                    if(mat[i][j]>len) len = mat[i][j];
                }
            }
        }
        return len*len;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h == 0) return 0;
        int w = matrix[0].size();
        vector<int> prev(w, 0);
        vector<int> curr(w, 0);
        int sz = 0;
        for(int i = 0; i < w; ++i) {
            curr[i] = matrix[0][i] - '0';
            sz = max(sz, curr[i]);
        }
        for(int i = 1; i < h; ++i) {
            prev = curr;
            curr[0] = matrix[i][0] - '0';
            for(int j = 1; j < w; ++j) {
                if(matrix[i][j] == '1') {
                    curr[j] = min(prev[j-1], min(prev[j], curr[j-1]))+1;
                    sz = max(sz, curr[j]);
                }
                else {  //Caution!!! we need to refresh curr with all 0 or set value for each element in curr
                    curr[j] = 0;
                }
            }
        }
        return sz*sz;
    }
};