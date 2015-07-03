// 137 Single Number II
// Given an array of integers, every element appears three times except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumberII(vector<int>& nums) {
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            t1 = t1^nums[i];
            t2 = t2 | ((t1^nums[i]) & nums[i]);
            t3 = ~(t1 & t2);
            t1 = t1 & t3;
            t2 = t2 & t3;
        }
        return t1;
    }

    int singleNumberII(vector<int> &A) {
        // write your code here
        int ones = 0;
        int twos = 0;
        for(int i = 0; i < A.size(); ++i) {
            ones = (ones^A[i]) & ~twos;
            twos = (twos^A[i]) & ~ones;
        }
        return ones;
    }
};