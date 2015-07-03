// 67 Add Binary
// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".
#include <string>
#include <iostream>
#include <algorithm>
using namespace::std;
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty() || a == "0") return b;
        if(b.empty() || b == "0") return a;
        if(a.size()<b.size()) swap(a,b);
        int na = a.size();
        int nb = b.size();
        int i = 0;
        int c = 0;
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while(i < nb) {
            res += ((a[i]-'0')^(b[i]-'0')^c)+'0';
            c = ((a[i]-'0')+(b[i]-'0')+c)/2;
            i++;
        }
        while(i < na) {
            res += (a[i]-'0')^c+'0';
            c = (a[i]-'0')&c;
            i++;
        }
        if(c) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }

    string addBinary2(string a, string b) {
        if(a.empty() || a == "0") return b;
        if(b.empty() || b == "0") return a;
        string res;
        int c = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        while(i >= 0 || j >= 0 || c == 1) {
            if(i >= 0) {
                c += a[i]-'0';
                i--;
            }
            if(j >= 0) {
                c += b[j]-'0';
                j--;
            }
            char ch = c%2+'0';
            res = ch+res;
            c = c/2;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string a = "1";
    string b = "111";
    Solution mySolution;
    string res = mySolution.addBinary2(a, b);
    cout<<res<<endl;
    return 0;
}