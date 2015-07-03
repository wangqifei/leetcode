// 27 Remove Element
// Given an array and a value, remove all instances of that value in place and return the new length.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int st = 0;
        int ed = nums.size()-1;
        while(st <= ed)
        {
            if(nums[st] == val)
            {
                nums[st] = nums[ed];
                ed--;
            }
            else
            {
                st++;
            }
        }
        return st;
    }
};