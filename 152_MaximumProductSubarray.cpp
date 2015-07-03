// 152 Maximum Product Subarray
// Find the contiguous subarray within an array (containing at least one number) which has the largest product.

// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

// Hide Tags Array Dynamic Programming

#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int min_prod = nums[0];
        int max_prod = nums[0];
        int max_res = nums[0]; //Caution!!! do not use INT_MIN, it is not necessary and it may not be updated when nums.size()<2
        for(int i = 1; i < nums.size(); ++i) {
            int prev_min_prod = min_prod;
            int prev_max_prod = max_prod;
            min_prod = min(min(prev_max_prod*nums[i], prev_min_prod*nums[i]), nums[i]);
            max_prod = max(max(prev_max_prod*nums[i], prev_min_prod*nums[i]), nums[i]);
            max_res = max(max_res, max(min_prod, max_prod));
        }
        return max_res;
    }
};

int main(int argc, char const *argv[])
{
    // int A[] = {-4,-3,-2};
    // int len = 3;
    int A[] = {-2};
    int len = 1;
    Solution mySolution;
    vector<int> nums(A, A+len);
    int res = mySolution.maxProduct(nums);
    cout<<res<<endl;
    return 0;
}