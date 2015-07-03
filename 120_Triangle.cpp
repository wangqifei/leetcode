// 120 Triangle
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

class Solution {
public:
    //top to bottom solution
    int minimumTotal(vector<vector<int> > &triangle) {
        int h = triangle.size();
        if(h == 0) return 0;
        if(h == 1) return triangle[0][0];
        vector<int> last_sum(triangle[0]);
        for(int i = 1; i < h; ++i) {
            int w = triangle[i].size();
            vector<int> cur_sum(w, 0);
            cur_sum[0] = triangle[i][0]+last_sum[0];
            for(int j = 1; j < w-1; ++j) {
                cur_sum[j] = min(last_sum[j-1], last_sum[j])+triangle[i][j];
            }
            cur_sum[w-1] = last_sum[w-2]+triangle[i][w-1];
            last_sum.clear();
            last_sum = cur_sum;
            for(int j = 0; j < last_sum.size(); ++j) {
                cout<<last_sum[j]<<" ";
            }
            cout<<endl;
        }
        int res = INT_MAX;
        for(int i = 0; i < last_sum.size(); ++i) {
            if(last_sum[i]<res) {
                res = last_sum[i];
            }
        }
        return res;
    }

    //more concise top down solution
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()) return 0;
        vector<vector<int> > triangle_sum(triangle);  //Caution init the same triangle for the sum iteration
        for(int i = 1; i < triangle.size(); ++i) {
            triangle_sum[i][0] = triangle_sum[i-1][0]+triangle[i][0];
            for(int j = 1; j < triangle[i].size()-1; ++j) {
                triangle_sum[i][j] = min(triangle_sum[i-1][j-1], triangle_sum[i-1][j])+triangle[i][j];
            }
            triangle_sum[i].back() = triangle_sum[i-1].back()+triangle[i].back();
        }
        int res = INT_MAX;
        for(int i = 0; i < triangle_sum.back().size(); ++i) {
            if(triangle_sum.back()[i]<res) {
                res = triangle_sum.back()[i];
            }
        }
        return res;
    }

    //bottom up solution
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()) return 0;
        vector<int> minrow = triangle.back();
        for(int i = triangle.size()-2; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                minrow[j] = min(minrow[j], minrow[j+1])+triangle[i][j];
            }
        }
        return minrow[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    int l1[] = {-1};
    int l2[] = {3,2};
    int l3[] = {-1,-2,-1};
    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(l1, l1+1));
    triangle.push_back(vector<int>(l2, l2+2));
    triangle.push_back(vector<int>(l3, l3+3));
    int res = mySolution.minimumTotal(triangle);
    cout<<res<<endl;
    return 0;
}