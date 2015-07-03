// 227 Basic Calculator II Total Accepted: 1256 Total Submissions: 6477 My Submissions Question Solution 
// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// You may assume that the given expression is always valid.

// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5
// Note: Do not use the eval built-in library function.

#include <iostream>
#include <string>
#include <sstream>
using namespace::std;

class Solution {
public:
    //the most concise solution, use stringstream to format the string into int and operator
    int calculate(string s) {
        istringstream in('+' + s + '+'); //require header file <sstream>
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' or op == '-') {
                total += term;
                in >> term;
                term *= 44 - op;
            } else {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }

    //this solution is eailier to understand. the idea is the same as the above one, also from oj leetcode discussion
    int calculate2(string s) {
        int i = 0;
        int last_num = getNextNum(s, i);
        int sign = 1;
        int res = 0;
        while(i<s.size()) {
            if(s[i] == '+') {
                res += sign*last_num;
                sign = 1;
                last_num = getNextNum(s, ++i);
            }
            else if(s[i] == '-') {
                res += sign*last_num;
                sign = -1;
                last_num = getNextNum(s, ++i);
            }
            else if(s[i] == '*') {
                last_num *= getNextNum(s, ++i);
            }
            else if(s[i] == '/') {
                last_num /= getNextNum(s, ++i);
            }
        }
        res += last_num*sign;
        return res;
    }

    int getNextNum(string& s, int& i) {
        int num = 0;
        while(i < s.size()) {
            if(isdigit(s[i])){
                num = num*10+s[i]-'0';
            }
            else if(s[i] != ' ') break;
            i++;
        }
        return num;
    }

    //in this problem, we should use long long to prevent the overflow of int
    long long getNextNum(string s, long long& i) {
        long long res = 0;
        while(i<s.size()) {
            if(isdigit(s[i])) {
                res = res*10+s[i]-'0';
            }
            else if(s[i] != ' ') break;
            i++;
        }
        return res;
    }
    int calculate(string s) {
        long long st = 0;
        long long curr_num = getNextNum(s, st);
        long long res = 0;
        int sign = 1;
        while(st<s.size()) {
            if(s[st] == '+') {
                res = res+sign*curr_num;
                sign = 1;
                st++;
                curr_num = getNextNum(s, st);
            }
            else if(s[st] == '-') {
                res = res+sign*curr_num;
                sign = -1;
                st++;
                curr_num = getNextNum(s, st);
            }
            else if(s[st] == '*') {
                st++;
                long long next_num = getNextNum(s, st);
                curr_num = curr_num*next_num;
            }
            else if(s[st] == '/') {
                st++;
                long long next_num = getNextNum(s, st);
                curr_num = curr_num/next_num;
            }
            else {
                st++;
            }
        }
        return res+=sign*curr_num;
    }
};

int main(int argc, char const *argv[])
{
    string s = " 3+5 / 2 ";
    Solution mySolution;
    int res = mySolution.calculate(s);
    cout<<res<<endl;
    return 0;
}