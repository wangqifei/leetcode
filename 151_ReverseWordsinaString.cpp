// 151 Reverse Words in a String
// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space.

// click to show clarification.

// Clarification:
// What constitutes a word?
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing spaces.
// How about multiple spaces between two words?
// Reduce them to a single space in the reversed string.
// Hide Tags String

#include <string>
#include <iostream>
using namespace::std;
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        int ed = s.size()-1;
        string rs;
        while(ed >= 0) {
            while(ed >= 0 && s[ed] == ' ') ed--;
            if(ed < 0) break;
            int st = ed;
            while(st >= 0 && s[st] != ' ') st--;
            if(st < ed) {
                string str = s.substr(st+1, ed-st);
                rs = rs + str + " ";
            }
            ed = st;
        }
        if(rs.empty() == false) rs.pop_back();
        s = rs;
    }
};

int main(int argc, char const *argv[])
{
	string s = " 1";
	Solution mySolution;
	mySolution.reverseWords(s);
	cout<<s<<endl;
	return 0;
}
