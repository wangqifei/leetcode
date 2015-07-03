// 34 Search for a Range
// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()) return res;
        int st = 0;
        int ed = nums.size()-1;
        //search for the lower bound
        while(st < ed)
        {
            int md = (st+ed)/2;
            if(nums[md] == target) ed = md;
            else if(nums[md] > target) ed = md-1;
            else st = md+1;
        }
        int res_st = nums[ed] == target?ed:-1;
        //search for the upper bound
        st = res_st;
        ed = nums.size()-1;
        while(st < ed)
        {
            int md = (st+ed+1)/2;  //make the md to the upper bound, otherwise, without+1, md = st will be a dead lock
            if(nums[md] == target) st = md;
            else if(nums[md] > target) ed = md-1;
            else st = md+1;
        }
        int res_ed = nums[st] == target?st:-1;
        res.push_back(res_st);
        res.push_back(res_ed);
    }
};