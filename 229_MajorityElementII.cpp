// 229 Majority Element II Total Accepted: 260 Total Submissions: 1180 My Submissions Question Solution 
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

// Hint:

// How many majority elements could it possibly have?

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        int num1;
        int num2;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < len; ++i) {
            if(cnt1 == 0) {num1 = nums[i]; cnt1 = 1; }
            else if(nums[i] == num1) cnt1++;
            else if(cnt2 == 0) { num2 = nums[i]; cnt2 = 1; }
            else if(nums[i] == num2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        //Caution!!! check if the num1 and num2 are the true one appears more than 1/3 times
        for(int i = 0; i < len; ++i) {
            if(nums[i] == num1) cnt1++;
            else if(nums[i] == num2) cnt2++;
        }
        if(cnt1>len/3) res.push_back(num1);
        if(cnt2>len/3) res.push_back(num2);
        return res;
    }
};