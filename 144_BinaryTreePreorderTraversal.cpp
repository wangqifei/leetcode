// 144 Binary Tree Preorder Traversal
// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        res.push_back(root->val);
        vector<int> lvec, rvec;
        if(root->left) {
            lvec = preorderTraversal(root->left);
        }
        if(root->right) {
            rvec = preorderTraversal(root->right);
        }
        res.insert(res.end(), lvec.begin(), lvec.end());
        res.insert(res.end(), rvec.begin(), rvec.end());
        return res;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(curr || st.empty() == false) {
            while(curr) {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            if(st.empty() == false) {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
    }

    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || st.empty() == false) {
            if(curr) {
                res.push_back(curr->val);
                if(curr->right) st.push(curr->right);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
            }
        }
    }
};