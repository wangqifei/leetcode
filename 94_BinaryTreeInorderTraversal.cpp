// 94 Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

// Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        vector<int> left_vec, right_vec;
        if(root->left) left_vec = inorderTraversal(root->left);
        if(root->right) right_vec = inorderTraversal(root->right);
        res.insert(res.end(), left_vec.begin(), left_vec.end());
        res.push_back(root->val);
        res.insert(res.end(), right_vec.begin(), right_vec.end());
        return res;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || st.empty() == false) {
            while(p) {
                st.push(p);
                p = p->left;
            }
            if(st.empty() == false) {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};