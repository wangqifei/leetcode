//4 Median of Two Sorted Arrays 
//There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)//)

class Solution {
public:
    int median(vector<int>& nums1, int st1, vector<int>& nums2, int st2, int n)
    {
        if(st1 == nums1.size()) return nums2[st2+n-1];
        if(st2 == nums2.size()) return nums1[st1+n-1];
        if(n == 1) return min(nums1[st1], nums2[st2]);
        if(nums1.size()-st1 > nums2.size()-st2) return median(nums2, st2, nums1, st1, n);  //Caution!!! must return
        int n1 = nums1.size()-st1;
        int l1 = min(n/2, n1);  //Caution!!! not max
        int l2 = n - l1;
        if(nums1[st1+l1-1] <= nums2[st2+l2-1])
            return median(nums1, st1+l1, nums2, st2, n-l1);
        else
            return median(nums1, st1, nums2, st2+l2, n-l2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if((n1+n2)%2)
            return double(median(nums1, 0, nums2, 0, (n1+n2)/2+1));
        else
            return double(median(nums1, 0, nums2, 0, (n1+n2)/2)+median(nums1, 0, nums2, 0, (n1+n2)/2+1))/2.0;
    }
};
