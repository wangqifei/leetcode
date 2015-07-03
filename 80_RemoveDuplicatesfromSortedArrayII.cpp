// 80 Remove Duplicates from Sorted Array II
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 1;
        int j = 1;
        int cnt = 1;
        while(j < n) {
            if(nums[j] != nums[j-1]) {
                nums[i] = nums[j];
                i++;
                j++;
                cnt = 1;
            }
            else {
                if(cnt<2) {
                    nums[i] = nums[j];
                    i++;
                    j++;
                    cnt++;
                }
                else {
                    j++;
                }
            }
        }
        return i;
    }

    //this is a general and beautiful solution
    int removeDuplicates(int A[], int n, int k) {

            if (n <= k) return n;

            int i = 1, j = 1;
            int cnt = 1;
            while (j < n) {
                if (A[j] != A[j-1]) {
                    cnt = 1;
                    A[i++] = A[j];
                }
                else {
                    if (cnt < k) {
                        A[i++] = A[j];
                        cnt++;
                    }
                }
                ++j;
            }
            return i;
}
};