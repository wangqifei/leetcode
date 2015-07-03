//12
// Integer to Roman Total Accepted: 31322 Total Submissions: 89727 My Submissions Question Solution 
// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.

// Symbol	Value
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1,000
#include <string>
#include <iostream>
using namespace::std;
class Solution {
public:
    string intToRoman(int num) {
        int nM = num/1000; num = num%1000;
        int nD = num/500;  num = num%500;
        int nC = num/100;  num = num%100;
        int nL = num/50;   num = num%50;
        int nX = num/10;   num = num%10;
        int nV = num/5;    num = num%5;
        int nI = num;

        string res;
        if(nM > 0) res += string(nM, 'M');
        if(nD == 1 && nC == 4) res += "CM";
        else if(nD == 0 && nC == 4) res += "CD";
        else{
        	if(nD == 1) res += "D";
        	res += string(nC, 'C');
        }
        if(nL == 1 && nX == 4) res += "XC";
        else if(nL == 0 && nX == 4) res += "XL";
        else{
        	if(nL == 1) res += "L";
        	res += string(nX, 'X');
        }
        if(nV == 1 && nI == 4) res += "IX";
        else if(nV == 0 && nI == 4) res += "IV";
        else{
        	if(nV == 1) res += "V";
        	res += string(nI, 'I');
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySolution;
	int num = 3000;
	string res = mySolution.intToRoman(num);
	cout<<num<<" is "<<res<<endl;
	return 0;
}