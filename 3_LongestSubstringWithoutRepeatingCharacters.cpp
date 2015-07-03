//3 Longest Substring Without Repeating Characters
//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int mask[256] = {0};
        int st = 1;
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mask[s[i]] != 0)
            {
                if(mask[s[i]] >= st)
                {
                    st = mask[s[i]]+1;
                }
            }
            mask[s[i]] = i+1;
            res = max(res, i-st+2);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySolution;
    int res = mySolution.lengthOfLongestSubstring("abca");
    cout<<"length is "<<res<<endl;
    return 0;
}