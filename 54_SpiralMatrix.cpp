// Spiral Matrix
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].
#include <vector>
#include <iostream>
using namespace::std;
class Solution {
public:
    //o(n) space o(n) time
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row == 0) return res;
        int col = matrix[0].size();
        vector<vector<bool> > mask(row, vector<bool>(col, false));
        res.push_back(matrix[0][0]);
        mask[0][0] = true;
        int i = 0; 
        int j = 0;
        int ind = 1;
        while(ind<row*col) {
            while(j < col-1 && mask[i][j+1] == false) {  //Caution!!! j must < col-1. otherwise, after j++, mask[i][j] will reach out of the matrix, test the next one, otherwise, when mask[i][j] == true, it will be a dead loop
                res.push_back(matrix[i][j+1]);
                mask[i][j+1] = true;
                j++;
                ind++;
            }
            while(i < row-1 && mask[i+1][j] == false) {
                res.push_back(matrix[i+1][j]);
                mask[i+1][j] = true;
                i++;
                ind++;
            }
            while(j > 0 && mask[i][j-1] == false) {
                res.push_back(matrix[i][j-1]);
                mask[i][j-1] = true;
                j--;
                ind++;
            }
            while(i > 0 && mask[i-1][j] == false) {
                res.push_back(matrix[i-1][j]);
                mask[i-1][j] = true;
                i--;
                ind++;
            }
        }
        return res;
    }

    //o(n) time o(1) space
    vector<int> spiralOrder2(vector<vector<int>>& matrix) {
        vector<int> res;
        int h = matrix.size();
        if(h == 0) return res;
        int w = matrix[0].size();
        int i = 0; 
        int j = 0;
        int c = w<h?(w+1)/2:(h+1)/2; //Caution!!! do not use c = w<h?w/2:h/2; c means the circus we need to run, for 2x3, we need to run 1 circus, for 3x4 we need to run 2 circus
        for(int i = 0; i < c; ++i, h -= 2, w -= 2) { //Caution! do not need to do it in a symmetric way
            for(int x = i; x < i+w; ++x) {
                res.push_back(matrix[i][x]);
            }
            for(int y = i+1; y < i+h; ++y) {
                res.push_back(matrix[y][i+w-1]);
            }
            if(h == 1 || w == 1) {break;}
            for(int x = i+w-2; x >= i; --x) {
                res.push_back(matrix[i+h-1][x]);
            }
            for(int y = i+h-2; y > i; --y) {
                res.push_back(matrix[y][i]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // const int h = 3;
    // const int w = 3;
    // int A[][w] = {1,2,3,4,5,6,7,8,9};
    const int h = 2;
    const int w = 3;
    int A[][w] = {1,2,3,4,5,6};
    vector<vector<int> > matrix(h, vector<int>(w, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            matrix[i][j] = A[i][j];
        }
    }
    Solution mySolution;
    vector<int> res = mySolution.spiralOrder2(matrix);
    for(int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}