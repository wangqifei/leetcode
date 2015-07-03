// 35 Search Insert Position
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

//Caution, if cannot find, the return value should be st
//because the target should be between ed and st, here ed = st-1. the position for target will be ed+1 which = st
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int st = 0;
        int ed = nums.size()-1;
        while(st <= ed)
        {
            //int md = (st+ed)/2;  //Caution
            int md = st+(ed-st)/2; // this can prevent overflow if ed is really large
            if(nums[md] == target) return md;
            else if(nums[md] > target) ed = md-1;
            else st = md+1;
        }
        return st;
    }
};