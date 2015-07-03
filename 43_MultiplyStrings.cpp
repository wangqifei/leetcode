// 43 Multiply Strings 
// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.
#include <string>
#include <iostream>
#include <algorithm>
using namespace::std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        int n = n1+n2-1;
        int c = 0;
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = 0; j <= min(i, n1-1); ++j)
            {
                if((i-j)<n2)
                    sum += (num1[j]-'0')*(num2[i-j]-'0');
            }
            char ch = (sum+c)%10+'0';
            c = (sum+c)/10;
            res += ch;
        }
        if(c)
            res += c+'0';
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    string num1 = "123";
    string num2 = "456";
    string res = mySolution.multiply(num1, num2);
    cout<<res<<endl;
    return 0;
}