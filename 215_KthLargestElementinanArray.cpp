// 215 Kth Largest Element in an Array Total Accepted: 8414 Total Submissions: 30828 My Submissions Question Solution 
// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

// Hide Tags Divide and Conquer Heap

#include <algorithm>
using namespace::std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
    int findKthLargest(vector<int>& nums, int k) {
    	
    }
};