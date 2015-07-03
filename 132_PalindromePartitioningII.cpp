// 132 Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <vector>
#include <string>
using namespace::std;
class Solution {
public:
    int minCut(string s) {
        if(s.size()<=1) return 0;
        int len = s.size();
        vector<vector<bool> > pal(len, vector<bool>(len, false));
        vector<int> d(len);
        for(int i = len-1; i >= 0; --i) {
            d[i] = len-i-1;
            for(int j = i; j < len; ++j) {
                if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1])) {  //Caution, the best dp solution for palindrome check
                    pal[i][j] = true;
                    if(j == len-1) d[i] = 0;
                    else {
                        if(d[j+1]+1<d[i]) d[i] = d[j+1]+1;
                    }
                }
            }
        }
        return d[0];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}