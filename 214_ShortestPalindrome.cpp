// 214 Shortest Palindrome Total Accepted: 3249 Total Submissions: 19360 My Submissions Question Solution 
// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

// For example:

// Given "aacecaaa", return "aaacecaaa".

// Given "abcd", return "dcbabcd".

// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.

// Hide Tags String


class Solution {
public:
    //MLE since using a two-dimensional array
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        int len = s.size();
        vector<vector<bool> > mat(len, vector<bool>(len, false));
        for(int i = len-1; i >= 0; --i) {
            for(int j = i; j < len; ++j) {
                if(s[i] == s[j] && (j-i<2 || mat[i+1][j-1])) {
                    mat[i][j] = true;
                }
            }
        }
        int ed = 0;
        for(; ed < len; ++ed) {
            if(mat[0][ed] == false) break;
        }
        string add = s.substr(ed);
        reverse(add.begin(), add.end());
        string res = add+s;
        return res;
    }

    //TLE since checking palindrome for each substring
    string shortestPalindrome2(string s) {
        if(s.empty()) return s;
        int len = s.size();
        vector<bool> pal(len, true);
        for(int i = 0; i < len; ++i) {
            int ed = i;
            int st = 0;
            while(st<ed) {
                if(s[st] != s[ed]) {
                    pal[i] = false;
                    break;
                }
                else {
                    st++;
                    ed--;
                }
            }
        }
        int ed = len-1;
        for(; ed >= 0; --ed) {
            if(pal[ed] == true) break;
        }
        string add = s.substr(ed);
        reverse(add.begin(), add.end());
        string res = add+s;
        return res;
    }

    //KMP solution
    string shortestPalindrome(string s) {
        if(s.size()<2) return s; 
        string revs = s;
        reverse(revs.begin(), revs.end());
        string ss = s+revs;
        int len = ss.size();
        vector<int> pi(len, 0);
        int k = 0;
        for(int i = 1; i < len; ++i) {
            while(k > 0 && ss[k] != ss[i]) {
                k = pi[k-1];  //k is the length of the longest prefix. we need to referer to k-1 in the prefix length array
            }
            k += ss[k]==ss[i];
            pi[i] = k;
        }
        return revs.substr(0, s.size()-pi[len-1])+s;
    }
};