// 136 Single Number
// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Hide Tags Hash Table Bit Manipulation


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            res = res^nums[i];
        }
        return res;
    }
};