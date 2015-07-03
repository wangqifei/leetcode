// 97 Interleaving String
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 == 0) return s3 == s2;
        if(len2 == 0) return s3 == s1;
        if(len1+len2 != len3) return false;
        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len1; ++i) {
            if(s1[i-1] == s3[i-1] && dp[i-1][0]) dp[i][0] = true;  //the interleaving should be consecutive, dp[i][j] means s3[0:i+j-1] = s1[0:i-1]+s2[0:j-1]
        }
        for(int i = 1; i <= len2; ++i) {
            if(s2[i-1] == s3[i-1] && dp[0][i-1]) dp[0][i] = true;
        }
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                if((dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]))
                    dp[i][j] = true;
            }
        }
        return dp[len1][len2];
    }
};