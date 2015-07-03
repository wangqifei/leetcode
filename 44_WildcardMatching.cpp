// 44 Wildcard Matching
// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty() && s.empty()) return true;
        if(p.empty()) return false;
        int star = -1;
        int si = 0;
        int i = 0;
        int j = 0;
        while(i < s.size())
        {
            if(j<p.size() && (p[j] == s[i] || p[j] == '?')){
                i++;
                j++;
                continue;
            }
            if(j < p.size() && p[j] == '*'){
                star = j;
                j++;
                si = i;
                continue;
            }
            if(star >= 0)
            {
                i = ++si;
                j = star+1;
                continue;
            }
            return false;
        }
        while(j < p.size() && p[j] == '*') j++;  //Caution!!! use while instand of if
        return j == p.size()? true:false;
    }
};