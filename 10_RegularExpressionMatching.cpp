//10 Regular Expression Matching
// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool> > mat(m+1, vector<bool>(n+1, false));
        mat[0][0]  = true;
        for(int i = 0; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(p[j-1] != '*')
                {
                    if(i > 0 && (p[j-1] == s[i-1] || p[j-1] == '.') && mat[i-1][j-1]) mat[i][j] = true;
                }
                else
                {
                    if(j > 1)
                    {
                        if(mat[i][j-1] || mat[i][j-2]) mat[i][j] = true;
                        else
                        {
                            if(i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && mat[i-1][j]) mat[i][j] = true;
                        }
                    }
                }
            }
        }
        return mat[m][n];
    }

    bool isMatch2(string s, string p) {
        if(p.empty()) return s.empty();
    	if(p[1] != '*'){
    		if(p[0] == s[0] || (p[0] == '.' && !s.empty()))
    			return isMatch2(s.substr(1), p.substr(1));
    		else
    		    return false;
    	}
    	else
    	{
    		while(s[0] == p[0] || (p[0] == '.' && !s.empty()))
    		{
    			if(isMatch2(s, p.substr(2))) return true;
    			s = s.substr(1);
    		}
    	}
    	return isMatch2(s, p.substr(2));
    }
};