// 140 Word Break II
// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].

// A solution is ["cats and dog", "cat sand dog"].

// Hide Tags Dynamic Programming Backtracking


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if(s.empty()) return res;
        if(mp.count(s)) return mp[s];
        if(wordDict.count(s)) res.push_back(s);
        for(int i = 1; i < s.size(); ++i) {
            if(wordDict.count(s.substr(i))) {
                vector<string> temp_res = wordBreak(s.substr(0,i), wordDict);
                for(int j = 0; j < temp_res.size(); ++j) {
                    temp_res[j] = temp_res[j] + ' ' + s.substr(i);
                }
                res.insert(res.end(), temp_res.begin(), temp_res.end());
            }
        }
        mp[s] = res;
        return res;
    }
private:
    unordered_map<string, vector<string> > mp;
};