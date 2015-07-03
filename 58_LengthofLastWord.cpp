// 58 Length of Last Word
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int st = s.size()-1;
        while(st >= 0 && s[st] == ' ') st--;
        if(st<0) return 0;
        int ed = st;
        while(ed>=0 && s[ed] != ' ') ed--;
        return st-ed;
    }
};