// Minimum Depth of Binary Tree
// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Caution, be careful of the case 
 //   1
 //  /
 // 2
 // the minimum depth here is 2, the depth is defined as the depth from root to the leaf. if the root does not have the right child, the depth of that node should be the depth to the left child
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL) return minDepth(root->right)+1;
        if(root->right == NULL) return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};