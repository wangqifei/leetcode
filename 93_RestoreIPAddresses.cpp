// 93 Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    bool isValidIP(string str) {
        if(str.size() == 3 && (atoi(str.c_str())>255||str[0] == '0')) return false;
        if(str.size() == 2 && str[0] == '0') return false;
        return true;
    }
    void dfs(string s, int cnt, string str, vector<string>& res) {
        if(cnt == 0) {
            if(s.size() == 0) {
                str.pop_back();
                res.push_back(str);
            }
            return;
        }
        for(int i = 1; i <= 3; ++i) {
            if(s.size()>=i && isValidIP(s.substr(0,i))) {
                dfs(s.substr(i), cnt-1, str+s.substr(0,i)+'.', res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string str;
        if(s.size()<4) return res;
        dfs(s, 4, str, res);
        return res;
    }
};