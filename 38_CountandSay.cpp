// 38 Count and Say
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return NULL;
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        char cur = str[0];
        int cnt = 0;
        string res;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == cur)
            {
                cnt++;
            }
            else
            {
                res += cnt+'0';
                res += cur;
                cur = str[i];
                cnt = 1;
            }
        }
        res += cnt+'0';
        res += cur;
        return res;
    }
};