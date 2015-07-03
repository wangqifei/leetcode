// 45 Jump Game II
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return 0;
        int canReach = 0;
        int numJumps = 0;
        int i = 0;
        while(i<nums.size())
        {
            canReach = max(canReach, i+nums[i]);
            if(canReach > 0) numJumps++;
            if(canReach >= nums.size()-1)
            {
                return numJumps;
            }
            int localMax = 0;
            for(int j = i+1; j <= canReach; ++j)
            {
                if(nums[j]+j>localMax)
                {
                    localMax = nums[j]+j;
                    i = j;
                }
            }
        }
        return numJumps;
    }
};

// This is the DP algorithm, but TLE
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if(nums.empty()) return true;
//         int canReach = 0;
//         vector<int> minStep(nums.size(),nums.size());
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             canReach = max(canReach, i+nums[i]);
//             if(canReach >= nums.size()-1)
//             {
//                 return minStep[i]+1;
//             }
//             for(int j = i+1; j <= canReach; ++j)
//             {
//                 minStep[j] = min(minStep[j], minStep[i]+1);
//             }
//         }
//         return minStep[nums.size()-1];
//     }
// };

// this backtracking or retrace algorithm also results in TLE
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         int i=n-1;
//         int step=0;
//         while(i>0){
//             for(int j=0;j<i;j++){
//                 if(nums[j]+j>=i){
//                     step++;
//                     i=j;
//                     break;
//                 }
//             }
//         }
//         return step;
//     }
// };