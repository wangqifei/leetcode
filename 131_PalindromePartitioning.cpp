//131 Palindrome Partitioning 
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

class Solution {
public:
    bool check(string s)
    {
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string s, int st, vector<string> vec, vector<vector<string>>& res)
    {
        if(st == s.size())
        {
            res.push_back(vec);
            return;
        }
        for(int i = st; i < s.size(); ++i)
        {
            if(check(s.substr(st, i-st+1)))
            {
                vec.push_back(s.substr(st, i-st+1));
                dfs(s, i+1, vec, res);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;
        vector<string> vec;
        dfs(s, 0, vec, res);
        return res;
    }
};