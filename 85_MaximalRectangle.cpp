// 85 Maximal Rectangle
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
#include <vector>
#include <iostream>
#include <stack>
using namespace::std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h == 0) return 0;
        int w = matrix[0].size();
        vector<int> histogram(w+1, 0);
        int res = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(matrix[i][j] == '1') {
                    histogram[j]++;
                }
                else {
                    histogram[j] = 0;  //Caution!!! if matrix[i][j] = 0, the previous count should be set to 0, only consecutive 1 will be added up
                }
            }
            // for(int j = 0; j < w+1; ++j) cout<<histogram[j]<<" ";
            // cout<<endl;
            stack<int> st;
            int k = 0;
            while(k < w+1) {
                if(st.empty() || histogram[k] >= histogram[st.top()]) {
                    st.push(k++);
                }
                else {
                    int temp = st.top();
                    st.pop();
                    res = max(res, histogram[temp]*(st.empty()? k:(k-st.top()-1)));
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    const int h = 2;
    const int w = 2;
    int A[][w] = {0,1,1,0};
    vector<vector<char> > matrix(h, vector<char>(w));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            matrix[i][j] = A[i][j] + '0';
        }
    }
    Solution mySolution;
    int res = mySolution.maximalRectangle(matrix);
    cout<<res<<endl;
    return 0;
}