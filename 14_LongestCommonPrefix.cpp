// 14 Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty()) return res;
        for(int i = 0; i < strs[0].size(); ++i)
        {
            for(int j = 1; j < strs.size(); ++j)
            {
                if(strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};