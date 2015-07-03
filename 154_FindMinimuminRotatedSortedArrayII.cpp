// 154 Find Minimum in Rotated Sorted Array II 
// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// The array may contain duplicates.

// Hide Tags Array Binary Search


class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int ed = nums.size()-1;
        while(st<ed) {
            int md = st+(ed-st)/2;
            if(nums[md] > nums[ed]) {
                st = md+1;
            }
            else if(nums[md] < nums[ed]) {
                ed = md;
            }
            else {
                ed--;
            }
        }
        return nums[st];
    }
};