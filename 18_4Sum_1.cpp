// 18 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        vector<int> vec;
        sort(nums.begin(), nums.end());
        kSum(nums, 0, nums.size()-1, target, 4, vec, res);
        return res;
    }

    void kSum(vector<int>& nums, int st, int ed, int target, int k, vector<int>& sol, vector<vector<int> >& res)
    {
        if(k == 2)
        {
            twoSum(nums, st, ed, target, sol, res);
            return;
        }
        for(int i = st; i <= ed-k+1; ++i) 
        {
            if(i > st && nums[i] == nums[i-1]) continue; //Caution i should be larger than st. if i is only larger than 0, some first i will be skipped
            sol.push_back(nums[i]);
            kSum(nums, i+1, ed, target-nums[i], k-1, sol, res); //Caution recursion with i+1, not st+1
            sol.pop_back();
        }
    }
    void twoSum(vector<int>& nums, int st, int ed, int target, vector<int>& sol, vector<vector<int> >& res)
    {
        while(st < ed)
        {
            int sum = nums[st]+nums[ed];
            if(sum == target)
            {
                sol.push_back(nums[st]);
                sol.push_back(nums[ed]);
                res.push_back(sol);
                sol.pop_back();
                sol.pop_back();
                st++;
                ed--;
                while(nums[st] == nums[st-1]) st++;
                while(nums[ed] == nums[ed+1]) ed--;
            }
            else if(sum < target) st++;
            else ed--;
        }
    }
};