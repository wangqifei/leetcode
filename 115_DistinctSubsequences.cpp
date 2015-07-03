// 115 Distinct Subsequences 
// Given a string S and a string T, count the number of distinct subsequences of T in S.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"

// Return 3.

class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.empty()) return 1;
        if(s.empty()) return 0;
        int sl = s.size();
        int tl = t.size();
        vector<vector<int> > dp(sl+1, vector<int>(tl+1, 0));
        for(int i = 0; i <= sl; ++i) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= sl; ++i) {
            for(int j = 1; j <= tl; ++j) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];  //caution!!! if s[i-1] != t[j-1], the number of substring in s[i-1] = t[j-1] should be the same as the substring in s[i-2]
                }
            }
        }
        return dp[sl][tl];
    }
};