// 8 String to Integer (atoi) Total Accepted: 47117 Total Submissions: 356920 My Submissions Question Solution 
// Implement atoi to convert a string to an integer.

// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

// spoilers alert... click to show requirements for atoi.

// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
#include <iostream>
#include <string>
#include <climits>
using namespace::std;
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int res = 0;
        int i = 0;
        bool sign = true;
        while(str[i] == ' ') i++;
        if(str[i] == '+') {sign = true; i++;}   //Caution!!! delete the prefix blank and determine the sign before the start of digit. if digit start, only digit can be accpeted, other following character will be denied
        else if(str[i] == '-') {sign = false; i++;}
        while(isdigit(str[i]))
        {
            if(res>INT_MAX/10) return sign?INT_MAX:INT_MIN;
            if(res == INT_MAX/10 && sign && str[i]>'7' && str[i]<='9') return INT_MAX;
            if(res == INT_MAX/10 && !sign && str[i] > '8'&& str[i]<='9') return INT_MIN;
            res = res*10+str[i]-'0';
            i++;
        }
        if(sign) return res;
        else return -res;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySolution;
	string s = " -1010023630o4";
	int res = mySolution.myAtoi(s);
	cout<<s<<" is "<<res<<endl;
	return 0;
}