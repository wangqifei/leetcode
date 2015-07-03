// 33 Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int st = 0;
        int ed = nums.size()-1;
        while(st <= ed)  //Caution!!! 
        {
            int md = (st+ed)/2; //if calculate md in this way, md might equal to st
            if(nums[md] == target) return md; 
            else if(nums[md]>=nums[st])  //Caution!!! if only >, when md == st, there is no solution
            {
                if(target >= nums[st] && target < nums[md]) ed = md-1;
                else st = md+1;
            }
            else
            {
                if(target > nums[md] && target <= nums[ed]) st = md+1;
                else ed = md-1;
            }
        }
        return -1;
    }
};