// 150 Evaluate Reverse Polish Notation
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
// Hide Tags Stack


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> st;
        int i = 0;
        while(i < tokens.size() && (i == 0 || st.empty() == false)) {
            if(tokens[i] == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2);
            }
            else if(tokens[i] == "-") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                num2 -= num1;
                st.push(num2);
            }
            else if(tokens[i] == "*") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                num2 *= num1;
                st.push(num2);
            }
            else if(tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                num2 /= num1;
                st.push(num2);
            }
            else {
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.top();
    }
};