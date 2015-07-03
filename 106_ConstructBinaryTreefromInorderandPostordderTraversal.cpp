// 106 Construct Binary Tree from Inorder and Postorder Traversal Total Accepted: 31956 Total Submissions: 119305 My Submissions Question Solution 
// Given inorder and postorder traversal of a tree, construct the binary tree.

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
 #include "BinaryTree.h"
 #include <vector>
 using namespace::std;
class Solution {
public:
    TreeNode* buildBT(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if(pe<ps) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ind = 0;
        for(int i = is; i <= ie; ++i) {
            if(inorder[i] == root->val) {  //root->val will be faster than use postorder[pe]
                ind = i;
                break;
            }
        }
        cout<<root->val<<endl;
        root->left = buildBT(inorder, postorder, is, ind-1, ps, ps+(ind-is)-1);
        root->right = buildBT(inorder, postorder, ind+1, ie, ps+(ind-is), pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        if(inorder.empty() && postorder.empty()) return NULL;
        TreeNode* root;
        buildBT(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> inorder({-1});
    // vector<int> postorder({-1});
    vector<int> inorder({4,2,5,1,3});
    vector<int> postorder({4,5,2,3,1});
    Solution mySolution;
    TreeNode* root = mySolution.buildTree(inorder, postorder);
    // BinaryTree BT;
    // BT.BinaryTreeLevelTraverse(root);
    return 0;
}