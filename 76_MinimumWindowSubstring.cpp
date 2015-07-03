// 76 Minimum Window Substring
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()) return s;
        if(t.empty()) return t;
        string res;
        int sn = s.size();
        int tn = t.size();
        if(sn<tn) return res;
        int srcCnt[256] = {0};
        int trgCnt[256] = {0};
        for(int i = 0; i < t.size(); ++i) {
            trgCnt[t[i]]++;
        }
        int st = 0;
        int minWindow = sn+1;
        int min_st = 0;
        int fndCnt = 0;
        for(int i = 0; i < sn; ++i) {
            if(trgCnt[s[i]] > 0) {
                srcCnt[s[i]]++; //Caution!!! the case that some characters are more than that in T is allowed 
                if(srcCnt[s[i]]<=trgCnt[s[i]]) { //should be <= not <
                    fndCnt++;
                    if(fndCnt == tn) {
                        while(st<sn && (trgCnt[s[st]] == 0 || srcCnt[s[st]]>trgCnt[s[st]])) {  //Caution srcCnt[i] can be larger than trgCnt[i]
                            if(trgCnt[s[st]]) srcCnt[s[st]]--;
                            st++;
                        }
                        if(minWindow>(i-st+1)) {
                            minWindow = i-st+1;
                            min_st = st;
                        }
                        srcCnt[s[st]]--;
                        fndCnt--;
                        st++;
                    }
                }
            }
        }
        if(minWindow != sn+1) {
            res = s.substr(min_st, minWindow);
        }
        return res;
    }
};