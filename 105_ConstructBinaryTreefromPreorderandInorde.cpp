// 105 Construct Binary Tree from Preorder and Inorder Traversal
// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

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
    TreeNode* buildBT(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int ind = 0;
        for(int i = is; i <= ie; ++i) {
            if(preorder[ps] == inorder[i]) {
                ind = i;
                break;
            }
        }
        root->left = buildBT(preorder, inorder, ps+1, ps+(ind-is), is, ind-1);
        root->right = buildBT(preorder, inorder, ps+(ind-is)+1, pe, ind+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        if(preorder.size() != inorder.size()) return NULL;
        TreeNode* root = buildBT(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};