// Text Justification
// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

// click to show corner cases.

// Corner Cases:
// A line other than the last line might contain only one word. What should you do in this case?
// In this case, that line should be left-justified.
#include <vector>
#include <string>
#include <iostream>
using namespace::std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0, k, l; i < words.size(); i += k) { //Caution! if k is not defined here, we cannot use i+=k
            for(k = 0, l = 0; i+k<words.size() && l+words[i+k].size()<=maxWidth-k; k++) { //Caution!!! the condition in for should be a logical expression, we cannot write condition a, condition b, we should write condition a & or | condition b
                l += words[i+k].size();
            }
            string curLine = words[i];
            for(int j = 1; j < k; ++j) {
                if(i+k>=words.size()) curLine += " ";
                //Caution, total space is mW-l, there are k words, k-1 intervals, the minimal space to each interval is mW-l/k-1
                else curLine += string((maxWidth-l)/(k-1)+((j-1)<((maxWidth-l)%(k-1))),' '); //(j-1)<((maxWidth-l)%(k-1)) define the extra space location, for example, if total space is 7, and there are four words, space allocation should be 3+2+2, the last one which is 7%3 is located to the head of the second word
                curLine += words[i+j];
            }
            curLine += string(maxWidth-curLine.size(), ' ');
            res.push_back(curLine);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    string word_str[] = {""};
    int n = 1;
    vector<string> words(word_str, word_str+n);
    int maxWidth = 0;
    vector<string> res = mySolution.fullJustify(words, maxWidth);
    for(int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
    return 0;
}