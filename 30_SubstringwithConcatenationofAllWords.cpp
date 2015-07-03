// 30 Substring with Concatenation of All Words
// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]

// You should return the indices: [0,9].
// (order does not matter).

class Solution {
public:
    bool check(string str, unordered_map<string, int>& mp, int wordLen)
    {
        unordered_map<string, int> mp1;
        for(int i = 0; i < str.length(); i = i+wordLen)
        {
            string w = str.substr(i,wordLen);
            if(!mp.count(w)) return false;
            mp1[w]++;
            if(mp1[w] > mp[w]) return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty()) return res;
        int wordNum = words.size();
        if(wordNum == 0) return res;
        int wordLen = words[0].size();
        int str_len = wordLen*wordNum;
        if(s.size() < str_len) return res;
        unordered_map<string, int> mp;
        for(int i = 0; i < wordNum; ++i) mp[words[i]]++;
        
        for(int i = 0; i <= s.length()-str_len; ++i)
        {
            if(check(s.substr(i, str_len), mp, wordLen)) res.push_back(i);
        }
        return res;
    }
};