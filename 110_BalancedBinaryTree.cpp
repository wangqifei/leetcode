// 110 Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    int TreeDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(TreeDepth(root->left), TreeDepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left_depth = TreeDepth(root->left);
        int right_depth = TreeDepth(root->right);
        if(left_depth - right_depth > 1 || right_depth - left_depth > 1)
            return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};