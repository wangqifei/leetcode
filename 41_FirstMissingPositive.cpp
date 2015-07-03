// 41 First Missing Positive
// Given an unsorted integer array, find the first missing positive integer.

// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.

// Your algorithm should run in O(n) time and uses constant space.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i+1 && nums[i] > 0 && nums[nums[i]-1] != nums[i] && nums[i]-1 < nums.size())
            {
                swap(nums[i], nums[nums[i]-1]);
            }
            else
            {
                i++;
            }
        }
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums[j]!=j+1) return j+1;
        }
        return nums.size()+1;
    }
};