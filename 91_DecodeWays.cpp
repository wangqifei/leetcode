// 91 Decode Ways
// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        if(s[0] == '0') dp[1] = 0;
        else dp[1] = 1;
        for(int i = 2; i <= len; ++i) {
            if(s[i-1] == '0' && (s[i-2] == '1' || s[i-2] == '2')) {
                dp[i] = dp[i-2];
            }
            else if(s[i-1] == '0' && (s[i-2] == '0' || s[i-2] > '2')) {
                return 0;
            }
            else if(s[i-2] == '2' && s[i-1] <= '6' && s[i-1] >= 1) {
                dp[i] = dp[i-2]+dp[i-1];
            }
            else if(s[i-2] == '0' && s[i-1] <= '9' && s[i-1] >= 1) {
                dp[i] = dp[i-1];
            }
            else if(s[i-2] == '1' && s[i-1] <= '9' && s[i-1] >= 1) {
                dp[i] = dp[i-1]+dp[i-2];
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[len];
    }
};