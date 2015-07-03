// 72 Edit Distance
// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// a) Insert a character
// b) Delete a character
// c) Replace a character
#include <string>
#include <vector>
#include <iostream>
using namespace::std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int> > mat(n1+1, vector<int>(n2+1, 0));
        for(int i = 1; i <= n1; ++i) {
            mat[i][0] = i;
        }
        for(int i = 1; i <= n2; ++i) {
            mat[0][i] = i;
        }
        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j <= n2; ++j) {
                if(word1[i-1] == word2[j-1]) {  //Caution, should be i-1 and j-1!!! not i, j
                    mat[i][j] = mat[i-1][j-1];
                }
                else {
                    mat[i][j] = 1+min(min(mat[i-1][j], mat[i-1][j-1]), mat[i][j-1]);
                }
            } 
        }
        cout<<mat[0][0]<<" "<<mat[0][1]<<" "<<mat[1][0]<<" "<<mat[1][1]<<endl;
        return mat[n1][n2];
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    string word1 = "a";
    string word2 = "b";
    int res = mySolution.minDistance(word1, word2);
    cout<<res<<endl;
    return 0;
}