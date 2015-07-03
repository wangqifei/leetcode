// 31 Next Permutation 
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

//Caution, find the first pair that i+1>i, then find the first nums[j]>nums[i], swap i, j and reverse from i+1 to the end
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i > 0)
        {
            if(nums[i]>nums[i-1])
            {
                int j = nums.size()-1;
                while(j > i-1)
                {
                    if(nums[j]>nums[i-1])
                    {
                        swap(nums[j], nums[i-1]);
                        reverse(nums.begin()+i, nums.end());
                        return;
                    }
                    j--;
                }
            }
            i--;
        }
        reverse(nums.begin(), nums.end());
    }
};