// 153 Find Minimum in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Hide Tags Array Binary Search


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return INT_MIN;
        int st = 0;
        int ed = nums.size()-1;
        while(st < ed) {
            int md = st+(ed-st)/2;
            if(nums[md] > nums[ed]) {
                st = md+1;
            }
            else {
                ed = md;
            }
        }
        return nums[st];
    }
};