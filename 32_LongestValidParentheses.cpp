// 32 Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

class Solution {
public:
    int longestValidParentheses(string s) {
        int last = -1;
        int i = 0;
        int max_len = 0;
        stack<int> st;
        while(i < s.length())
        {
            if(s[i] == '(') st.push(i);
            else{
                if(st.empty()) last = i;
                else{
                    st.pop();
                    if(st.empty()) max_len = max(max_len, i-last);
                    else max_len = max(max_len, i-st.top());
                }
            }
            i++;
        }
        return max_len;
    }
};