// 17 Letter Combinations of a Phone Number

// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.



// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.


class Solution {
public:
    void dfs(string& digits, int st, unordered_map<char, vector<char> >& mp, string str, vector<string>& res)
    {
        if(st == digits.size())
        {
            res.push_back(str);
            return;
        }
        char c = digits[st];
        vector<char> vec = mp[c];
        for(int i = 0; i < vec.size(); ++i)
        {
            str += vec[i];
            dfs(digits, st+1, mp, str, res);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        unordered_map<char, vector<char> > mp;
        mp.insert(make_pair('2', vector<char>{'a','b','c'}));
        mp.insert(make_pair('3', vector<char>{'d','e','f'}));
        mp.insert(make_pair('4', vector<char>{'g','h','i'}));
        mp.insert(make_pair('5', vector<char>{'j','k','l'}));
        mp.insert(make_pair('6', vector<char>{'m','n','o'}));
        mp.insert(make_pair('7', vector<char>{'p','q','r','s'}));
        mp.insert(make_pair('8', vector<char>{'t','u','v'}));
        mp.insert(make_pair('9', vector<char>{'w','x','y','z'}));
        
        string str;
        dfs(digits, 0, mp, str, res);
        return res;
    }
};