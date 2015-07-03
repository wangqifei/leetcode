// 139 Word Break
// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].

// Return true because "leetcode" can be segmented as "leet code".

// Hide Tags Dynamic Programming


class Solution {
public:
    //this recursive solution is TLE
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return true;
        for(int i = 1; i <= s.size(); ++i) {
            string str = s.substr(0, i);
            if(wordDict.find(str) != wordDict.end()) {
                if(wordBreak(s.substr(i),wordDict))
                    return true;
            }
        }
        return false;
    }

    //this dp solution 12 ms. idea from oj leetcode discussion
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return false;
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[len] = true;
        for(int i = len-1; i >= 0; --i) {
            for(int j = i+1; j <= len; ++j) {
                if(wordDict.count(s.substr(i,j-i)) && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};