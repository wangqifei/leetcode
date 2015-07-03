// 205 Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

// Hide Tags Hash Table


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int len = s.length();
        unordered_map<char, char> mps;  //Caution, we need two map to map s to t and t to s, otherwise, it cannot solve the case s=ab, b = bb
        unordered_map<char, char> mpt;
        for(int i = 0; i < len; ++i) {
            if(mps.count(s[i]) == 0 && mpt.count(t[i]) == 0) {
                mps.insert(make_pair(s[i], t[i]));
                mpt.insert(make_pair(t[i], s[i]));
            }
            else {
                if(mps[s[i]] != t[i] || mpt[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    //the same idea, but much faster than the one use unordered_map
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int len = s.length();
        unsigned char maps[256] = {0};
        unsigned char mapt[256] = {0};
        for(int i = 0; i < len; ++i) {
            if(maps[s[i]] == 0 && mapt[t[i]] == 0) {
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
            }
            else {
                if(maps[s[i]]!=t[i] || mapt[t[i]]!=s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};