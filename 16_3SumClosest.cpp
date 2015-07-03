// 16 3Sum Closest
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//     For example, given array S = {-1 2 1 -4}, and target = 1.

//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2]; //Caution!!! do not randomly choose the initial res value. If set res=INT_MAX or INT_MIN, if the target = -1 or 1, res+target will overflow
        for(int i = 0; i < nums.size()-2; ++i)
        {
            int st = i+1;
            int ed = nums.size()-1;
            while(st < ed)
            {
                int temp = nums[i]+nums[st]+nums[ed];
                if(temp<target)
                {
                    st++;
                }
                else if(temp>target)
                {
                    ed--;
                }
                else
                {
                    return target;
                }
                
                if(abs(temp-target)<abs(res-target))
                {
                    res = temp;
                }
            }
        }
        return res;
    }
};