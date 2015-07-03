// 28 Implement strStr() 
// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Update (2014-11-02):
// The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.size()-needle.size();
        for(int i = 0; i <= len; ++i)
        {
            int j = 0;
            while(j < needle.size())
            {
                if(haystack[i+j] != needle[j]) break;
                j++;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};