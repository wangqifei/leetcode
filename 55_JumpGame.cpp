// 55 Jump Game
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i <= canReach)
            {
                canReach = max(canReach, nums[i]+i);
                if(canReach >= nums.size()-1) return true;
            }
        }
        return false;
    }

    bool canJump2(vector<int>& nums){
        int canReach = 0;
        int i = 0;
        while(i < nums.size())
        {
            canReach = max(canReach, i+nums[i]);
            if(canReach >= nums.size()-1) return true;
            int localMax = 0;
            for(int j = 0; j <= canReach; ++j)
            {
                if(j+nums[j]>localMax)
                {
                    localMax = j+nums[j];
                    i = j;
                }
            }
        }
        return false;
    }
};