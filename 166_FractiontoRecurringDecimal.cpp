// 166 Fraction to Recurring Decimal
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// For example,

// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".
// Credits:
// Special thanks to @Shangrila for adding this problem and creating all test cases.

// Hide Tags Hash Table Math
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
using namespace::std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        if(denominator == 0) return NULL;
        string res;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0) ) res += '-';
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        long long i = n/d;
        long long r = n-i*d;
        res += to_string(i);
        if(r == 0) return res;
        
        string decimal;
        bool isRecur = false;
        map<long long, int> mp;
        mp.insert(make_pair(r, 0));
        int cur = 0;
        int st = 0;
        while(true) {
            long long m = r*10/d;
            decimal += m+'0';
            r = r*10-m*d;
            if(r == 0) break;
            else if(mp.count(r)) {
                st = mp[r];
                isRecur = true;
                break;
            }
            else {
                mp.insert(make_pair(r, ++cur));
            }
        }
        if(isRecur) {
            string decimal_nonrecur = decimal.substr(0, st);
            string decimal_recur = decimal.substr(st);
            res += '.'+decimal_nonrecur+'('+decimal_recur+')';
        }   
        else {
            res += '.'+decimal;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = -50;
    int d = 8;
    Solution mySolution;
    string res = mySolution.fractionToDecimal(n,d);
    cout<<res<<endl;
    return 0;
}