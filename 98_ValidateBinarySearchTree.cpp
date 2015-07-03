// 98 Validate Binary Search Tree
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left) {
            if(isValidBST(root->left) == false) return false;
            TreeNode* leftMaxNode = root->left;
            while(leftMaxNode->right) leftMaxNode = leftMaxNode->right;
            if(leftMaxNode->val >= root->val) return false;
        }
        if(root->right) {
            if(isValidBST(root->right) == false) return false;
            TreeNode* rightMinNode = root->right;
            while(rightMinNode->left) rightMinNode = rightMinNode->left;
            if(rightMinNode->val <= root->val) return false;
        }
        return true;
    }

    bool isValidBST2(TreeNode* root) {
        TreeNode* prev = NULL;
        return check(root, prev);
    }
    bool check(TreeNode* root, TreeNode*& prev) { //Caution, to remember the last node, we need to use reference pointer here!!!
        if(root == NULL) return true;
        if(check(root->left, prev) == false) return false;
        if(prev != NULL && root->val <= prev->val) return false;
        prev = root;
        if(check(root->right, prev) == false) return false;
        return true;
    }
};