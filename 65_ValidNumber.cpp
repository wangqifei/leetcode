// 65 Valid Number
// Validate if a given string is numeric.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
#include <string>
#include <iostream>
using namespace::std;
class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        enum INPUT_TYPE {INVALID, SPACE, DIGIT, SIGN, DOT, EXP};
        int stateTrans[][6] = {
        //   N,  S,  1,  +,  .,  e
            -1,  0,  1,  2,  3, -1,     //0 initial state
            -1,  8,  1, -1,  4,  5,     //1 after digit
            -1, -1,  1, -1,  3, -1,     //2 after sign
            -1, -1,  4, -1, -1, -1,     //3 after only dot
            -1,  8,  4, -1, -1,  5,     //4 after digit+dot
            -1, -1,  7,  6, -1, -1,     //5 after exp
            -1, -1,  7, -1, -1, -1,     //6 after exp+sign
            -1,  8,  7, -1, -1, -1,     //7 after exp+digit
            -1,  8, -1, -1, -1, -1,     //8 after valid num
        };
        int state = 0;
        for(int i = 0; i < s.size(); ++i) {
            INPUT_TYPE INPUT = INVALID;
            if(s[i] == ' ')                     INPUT = SPACE; 
            else if(s[i] >= '0' && s[i] <= '9') INPUT = DIGIT;
            else if(s[i] == '+' || s[i] == '-') INPUT = SIGN;
            else if(s[i] == '.')                INPUT = DOT;
            else if(s[i] == 'e' || s[i] == 'E') INPUT = EXP;
            state = stateTrans[state][INPUT];
            if(state == -1) return false;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    // string s = "e9"; //false
    // string s = "3."; //true
    // string s = "."; //false
    // string s = ".1." //false
    // string s = "3.5e+3.5e+3.5"; //false
    string s = ".0e"; //false
    string s = "46.e3"; //true
    string s = "6e6.5"; //false
    string s = "0e"; //false
    bool res = mySolution.isNumber(s);
    cout<<s<<" is number? "<<res<<endl;
    return 0;
}