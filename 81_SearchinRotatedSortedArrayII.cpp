// 81 Search in Rotated Sorted Array II
// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?

// Write a function to determine if a given target is in the array.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        int st = 0;
        int ed = n-1;
        while(st<=ed) {
            int md = st+(ed-st)/2;
            if(nums[md] == target) return true;
            if(nums[md] > nums[st]) {
                if(target<nums[md] && target >= nums[st]) {
                    ed = md-1;
                }
                else {
                    st = md+1;
                }
            }
            else if(nums[md]<nums[st]) {
                if(target>nums[md] && target<=nums[ed]) {
                    st = md+1;
                }
                else {
                    ed = md-1;
                }
            }
            else
                st++;
        }
        return false;
    }
};