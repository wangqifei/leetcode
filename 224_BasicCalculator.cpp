// 224 Basic Calculator Total Accepted: 95 Total Submissions: 695 My Submissions Question Solution 
// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23
// Note: Do not use the eval built-in library function.

class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        stack<int> st_num;
        stack<int> st_sign;
        int res = 0;
        int sign = 1;
        int i = 0;
        while(i<s.size()) {
            while(s[i] == ' ') i++;
            if(isdigit(s[i])) {
                int st = i;
                while(isdigit(s[i])) i++;
                int num = stoi(s.substr(st, i-st).c_str());
                res += sign * num;
            }
            if(s[i] == '+') {
                sign = 1;
                i++;
            }
            if(s[i] == '-') {
                sign = -1;
                i++;
            }
            if(s[i] == '(') {
                st_num.push(res);
                st_sign.push(sign);
                sign = 1;
                res = 0;
                i++;
            }
            if(s[i] == ')') {
                int prev_num = st_num.top();
                int prev_sign = st_sign.top();
                st_num.pop();
                st_sign.pop();
                res = prev_num+prev_sign*res;
                i++;
            }
        }
        return res;
    }

    int calculate2(string s) {
        stack<int> st_sign;
        stack<int> st_nums;
        int sign = 1;
        int res = 0;
        int num = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') continue;
            else if(isdigit(s[i])) num = num*10+s[i]-'0';
            else if(s[i] == '+') { 
                res = res+sign*num; 
                sign = 1;
                num = 0;
            }
            else if(s[i] == '-') {
                res = res+sign*num;
                sign = -1;
                num = 0;
            }
            else if(s[i] == '(') {
                st_nums.push(res);
                st_sign.push(sign);
                num = 0;
                sign = 1;
                res = 0;
            }
            else if(s[i] == ')') {
                res = res+sign*num;
                int prev_sums = st_nums.top();
                int prev_sign = st_sign.top();
                st_nums.pop();
                st_sign.pop();
                res = prev_sums+prev_sign*res;
                sign = 1;
                num = 0;
            }
        }
        if(num) res = res+num*sign;
        return res;
    }
};