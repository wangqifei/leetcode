// 48 Rotate Image 
// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        int st = 0;
        int ed = n-1;
        while(st < ed)
        {
            for(int i = 0; i < n; ++i)
            {
                swap(matrix[i][st], matrix[i][ed]);
            }
            st++;
            ed--;
        }
    }
};