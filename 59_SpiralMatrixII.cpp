// 59 Spiral Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
#include <vector>
#include <iostream>
using namespace::std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if(n == 0) return res;
        int num = n*n;
        int i = 0;
        int j = 0;
        int k = 1;
        res[0][0] = 1;
        while(k < num) {
            while(j+1 < n && res[i][j+1] == 0) {
                res[i][j+1] = ++k;
                j++;
            } 
            while(i+1 < n && res[i+1][j] == 0) {
                res[i+1][j] = ++k;
                i++;
            }
            while(j>0 && res[i][j-1] == 0) {
                res[i][j-1] = ++k;
                j--;
            }
            while(i>0 && res[i-1][j] == 0) {
                res[i-1][j] = ++k;
                i--;
            }
        }
        return res;
    }

    vector<vector<int> > generateMatrix2(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if(n == 0) return res;
        int m = (n+1)/2;
        int val = 0;
        for(int i = 0; i < m; ++i, n -= 2) {
            for(int col = i; col < i+n; ++col) {
                res[i][col] = ++val;
            }
            for(int row = i+1; row < i+n; ++row) {
                res[row][i+n-1] = ++val;
            }
            if(n == 1) break;
            for(int col = i+n-2; col >= i; --col) {
                res[i+n-1][col] = ++val;
            }
            for(int row = i+n-2; row > i; --row) {
                res[row][i] = ++val;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    int n = 4;
    vector<vector<int> > res = mySolution.generateMatrix2(n);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}