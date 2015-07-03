// 168 Excel Sheet Column Title
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
#include <string>
#include <algorithm>
using namespace::std;
class Solution {
public:
    string convertToTitle(int n) {
        if(n<=0) return NULL;
        string res;
        while(n > 0) {
            int i = (n-1)%26;
            res += 'A'+i;
            n = (n-i)/26;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string convertToTitle2(int n) {
        if(n<=0) return NULL;
        string res;
        while(n > 0) {
            int i = (n-1)%26;
            char ch = 'A'+i; 
            res = ch+res; //Caution, it cannot be written as res = 'A'+i+res because 'A'+i will be done as int+int since i is int. int+string is not acceptable
            n = (n-i)/26;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}