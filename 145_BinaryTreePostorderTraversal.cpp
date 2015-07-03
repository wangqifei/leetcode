// 145 Binary Tree Postorder Traversal
// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

// Note: Recursive solution is trivial, could you do it iteratively?

// Hide Tags Tree Stack


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        vector<int> lvec = postorderTraversal(root->left);
        vector<int> rvec = postorderTraversal(root->right);
        res.insert(res.end(), lvec.begin(), lvec.end());
        res.insert(res.end(), rvec.begin(), rvec.end());
        res.push_back(root->val);
        return res;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(st.empty() == false) {
            TreeNode* curr = st.top();
            st.pop();
            res.push_back(curr->val);
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};