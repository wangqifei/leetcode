// 213 House Robber II Total Accepted: 4909 Total Submissions: 18585 My Submissions Question Solution 
// Note: This is an extension of House Robber.

// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 // Dynamic Programming


Hide Tags Dynamic Programming
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int pre1 = 0;
        int pre2 = 0;
        int cur1 = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            pre2 = pre1;
            pre1 = cur1;
            cur1 = max(pre2+nums[i], pre1);
        }
        pre1 = 0;
        pre2 = 0;
        int cur2 = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            pre2 = pre1;
            pre1 = cur2;
            cur2 = max(pre2+nums[i], pre1);
        }
        return max(cur1, cur2);
    }
};