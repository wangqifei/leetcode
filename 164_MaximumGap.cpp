// 164 Maximum Gap
// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

// Try to solve it in linear time/space.

// Return 0 if the array contains less than 2 elements.

// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

// Credits:
// Special thanks to @porker2008 for adding this problem and creating all test cases.

// Hide Tags Sort


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int sz = nums.size();
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for(int i = 0; i < sz; ++i) {
            if(nums[i] > max_num) max_num = nums[i];
            if(nums[i] < min_num) min_num = nums[i];
        }
        int bucket_size = max(1, (max_num-min_num)/(sz-1));
        int bucket_num = (max_num-min_num)/bucket_size + 1; //Caution, +1 to make sure that there are enough buckets 
        if(bucket_num <= 1) return max_num-min_num;
        vector<int> bucket_min(bucket_num, INT_MAX);
        vector<int> bucket_max(bucket_num, INT_MIN);
        vector<int> bucket_cnt(bucket_num, 0);
        for(int i = 0; i < sz; ++i) {
            int bucket_idx = (nums[i]-min_num)/bucket_size;
            bucket_cnt[bucket_idx]++;
            bucket_min[bucket_idx] = min(nums[i], bucket_min[bucket_idx]);
            bucket_max[bucket_idx] = max(nums[i], bucket_max[bucket_idx]);
        }
        int last = min_num;
        int max_gap = 0;
        for(int i = 0; i < bucket_num; ++i) {
            if(bucket_cnt[i]>0) {
                max_gap = max(max_gap, bucket_min[i]-last);
                max_gap = max(max_gap, bucket_max[i]-bucket_min[i]);
                last = bucket_max[i];
            }
        }
        return max_gap;
    }
};