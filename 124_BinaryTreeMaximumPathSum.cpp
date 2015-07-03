// 124 Binary Tree Maximum Path Sum
// Given a binary tree, find the maximum path sum.

// The path may start and end at any node in the tree.

// For example:
// Given the below binary tree,

//        1
//       / \
//      2   3
// Return 6.


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
    int maxSum(TreeNode* root, int& res) {
        if(root == NULL) return 0;
        int sl = maxSum(root->left, res);
        int sr = maxSum(root->right, res);
        int cur_max_sum = max(max(sl+root->val, sr+root->val), root->val);
        int all_max_sum = max(cur_max_sum, sl+sr+root->val);
        if(all_max_sum > res) res = all_max_sum;
        return cur_max_sum;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int res = INT_MIN;
        maxSum(root, res);
        return res;
    }
};