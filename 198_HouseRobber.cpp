// 198 House Robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

// Hide Tags Dynamic Programming

class Solution {
public:
    int rob(vector<int> &nums) {
    	if(nums.empty()) return 0;
    	int odd = 0;
    	int even = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(i%2)
    		{
    			odd = max(odd+nums[i], even);
    		}
    		else
    		{
    			even = max(even+nums[i], odd);
    		}
    	}
    	return max(odd, even);
    }

    int rob2(vector<int>& nums) {
        if(nums.empty()) return 0;
        int prev2 = 0;
        int prev = 0;
        int curr = nums[0];
        int res = curr;
        for(int i = 1; i < nums.size(); ++i) {
            prev2 = prev;
            prev = curr;
            res = max(prev2+nums[i], prev);
            curr = res;
        }
        return res;
    }

    //more concise than rob2
    int rob3(vector<int>& nums) {
        if(nums.empty()) return 0;
        int prev2 = 0;
        int prev = 0;
        int curr = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            prev2 = prev;
            prev = curr;
            curr = max(prev2+nums[i], prev);
        }
        return curr;
    }
};
