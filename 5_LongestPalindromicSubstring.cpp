//Caution!!! do not get the substr in each loop, record the max_st and max_len, otherwise it will return TLE(time limit exceeds)
//5 Longest Palindromic Substring 
//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() == 1) return s;
        int n = s.size();
        int max_st = 0;
        int max_len = 1;
        bool mask[1000][1000] = {false};  //Caution, the problem has limit the maximum length of S is 1000, using vector may reduce the efficiency
        for(int i = 0; i < n; ++i) mask[i][i] = true;
        for(int i = 0; i < n-1; ++i) 
        {
            if(s[i] == s[i+1])
            {
                mask[i][i+1] = (s[i]==s[i+1]);
                max_st = i;
                max_len = 2;
            }
        }
        for(int i = 3; i <= n; ++i)
        {
            for(int j = 1; j < n-i+2; ++j)
            {
                if(mask[j][j+i-3] && s[j-1] == s[j+i-2])
                {
                    mask[j-1][j+i-2] = true;
                    max_st = j-1;
                    max_len = i;
                }
            }
        }
        return s.substr(max_st, max_len);
    }

    //this algorithm is a little slower than the above one since it does some comparison for the case i = j
    string longestPalindrome2(string s) {
        if(s.empty() || s.size() == 1) return s;
        int n = s.size();
        bool mat[1000][1000] = {false};
        int max_st = 0;
        int max_len = 1;
        for(int i = n-1; i >= 0; --i)
        {
            for(int j = i; j < n; ++j)
            {
                if(s[i]==s[j] &&((j-i)<2||mat[i+1][j-1]))
                {
                    mat[i][j] = true;
                    if(j-i+1>max_len)
                    {
                        max_st = i;
                        max_len = j-i+1;
                    }
                }
            }
        }
        return s.substr(max_st, max_len);
    }
};