// 88 Merge Sorted Array
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m+n-1;
        --m;
        --n;
        while(n>=0 && m >= 0) {
            nums1[l--] = nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
        }
        //Caution!!! when m goes to -1 first, the above code will access num1[-1]
        while(n>=0) {
            nums1[l--] = nums2[n--];
        }
    }
};