// 226 Invert Binary Tree Total Accepted: 15364 Total Submissions: 43445 My Submissions Question Solution 
// Invert a binary tree.

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// to
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
// Trivia:
// This problem was inspired by this original tweet by Max Howell:
// Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
// Hide Tags Tree

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* invertLeft = invertTree(root->left);
        TreeNode* invertRight = invertTree(root->right);
        root->left = invertRight;
        root->right = invertLeft;
        return root;
    }

    //iterative solution using stack, we can also do it with queue
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(st.empty() == false) {
            TreeNode* node = st.top();
            st.pop();
            if(node) {
                swap(node->left, node->right);
                st.push(node->left);
                st.push(node->right);
            }
        }
        return root;
    }
};