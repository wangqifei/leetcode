// Sort Colors
// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

// click to show follow up.

// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

// Could you come up with an one-pass algorithm using only constant space?

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size()-1;
        for(int i = 0; i <= blue; ++i) {
            while(nums[i] == 2 && i < blue) { //Caution!!! start from the back
                swap(nums[i], nums[blue]);
                blue--;
            }
            while(nums[i] == 0 && i > red) {
                swap(nums[i], nums[red]);
                red++;
            }
        }
    }

    void sortColors2(int A[], int n) {
        int i = 0, j = n-1;
        for(int k=0; k<=j; )
        {
            if(A[k]==0)  swap(A[i++], A[k++]);
            else if(A[k]==2)  swap(A[j--], A[k]);
            else k++;
        }        
    }
};