// 20 Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> st;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i++]);
                continue;
            }
            if((s[i] == ')' && !st.empty() && st.top() == '(') || 
            (s[i] == ']' && !st.empty() && st.top() == '[') ||
            (s[i] == '}' && !st.empty() && st.top() == '{')){
                st.pop();
                i++;
                continue;
            }
            return false;
        }
        if(st.empty()==false) return false;
        else return true;
    }
};