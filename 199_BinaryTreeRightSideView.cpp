// 199 Binary Tree Right Side View
// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

// Credits:
// Special thanks to @amrsaqr for adding this problem and creating all test cases.

// Hide Tags Tree Depth-first Search Breadth-first Search


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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i == sz-1) {
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }
};