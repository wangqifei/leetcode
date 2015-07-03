// 169 Majority Element
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Hide Tags Divide and Conquer Array Bit Manipulation


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int num = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == num) {
                cnt++;
            }
            else {
                if(cnt > 0) cnt--;
                else {
                    cnt = 1;
                    num = nums[i];
                }
            }
        }
        return num;
    }
};