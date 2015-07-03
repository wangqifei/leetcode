// Climbing Stairs 
// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(n+1, 0);
        ways[0] = 1; //Caution!!! if n== 2, there are two different ways to reach 2
        ways[1] = 1;
        for(int i = 2; i <= n; ++i) {
            ways[i] = ways[i-2]+ways[i-1];
        }
        return ways[n];
    }
    int climbStairs2(int n) {
    	if(n == 1) return 1;
    	int curr = 1;
    	int pre1 = 1;
    	int pre2 = 0;
    	int i = 2;
    	while(i <= n) {
    		pre2 = pre1;
    		pre1 = curr;
    		curr = pre1+pre2;
    		i++;
    	}
    	return curr;
    }
    //recursive solution, TLE
    int climbStairs3(int n) {
    	if(n == 0) return 1;
    	if(n == 1) return 1;
    	int res;
    	if(n>1)
    		res = climbStairs3(n-2)+climbStairs3(n-1);
    	return res;
    }
};