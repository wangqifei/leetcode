// 172 Factorial Trailing Zeroes
// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.

class Solution {
public:
    int trailingZeroes(int n) {
        int x = 0;
        while(n>0) {
            x += n/5;
            n = n/5;
        }
        return x;
    }

    //recursive solution, code from oj leetcode discussion, a little faster than iterative solution
    int trailingZeroes2(int n) {
    	return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};