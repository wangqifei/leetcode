// 108 Convert Sorted Array to Binary Search Tree
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBT(vector<int>& nums, int st, int ed) {
        if(st > ed) return NULL;
        int n = st+(ed-st)/2;
        TreeNode* root = new TreeNode(nums[n]);
        root->left = buildBT(nums, st, n-1);
        root->right = buildBT(nums, n+1, ed);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        return buildBT(nums, 0, nums.size()-1);
    }
};