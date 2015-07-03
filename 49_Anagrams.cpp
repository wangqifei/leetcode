// Anagrams
// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> res;
        if(strs.size()<2) return res;
        unordered_map<string, int> mp;
        for(int i = 0; i < strs.size(); ++i)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            if(mp.find(str) == mp.end()){
                mp.insert(make_pair(str,i));
            }
            else{
                if(mp[str] >= 0)
                {
                    res.push_back(strs[mp[str]]);
                }
                res.push_back(strs[i]);
                mp[str] = -1;
            }
        }
        return res;
    }
};