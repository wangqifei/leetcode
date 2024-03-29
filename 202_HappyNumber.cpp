// 202 Happy Number
// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Credits:
// Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

// Hide Tags Hash Table Math


class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_map<int, int> mp;
        while(n != 1) {
            int val = 0;
            while(n>0) {
                int m = n%10;
                val += m*m;
                n = n/10;
            }
            if(mp.count(val)) return false;
            else mp.insert(make_pair(val, 0));
            n = val;
        }
        return true;
    }
};