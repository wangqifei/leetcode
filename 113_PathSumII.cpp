// 113 Path Sum II 
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    void dfs(TreeNode* root, int sum, vector<int> vec, vector<vector<int> >& res) {
        if(root->val == sum && root->left == NULL && root->right == NULL) {
            vec.push_back(root->val);
            res.push_back(vec);
            return;
        }
        if(root->left) {
            vec.push_back(root->val);
            dfs(root->left, sum - root->val, vec, res);
            vec.pop_back();
        }
        if(root->right) {
            vec.push_back(root->val);
            dfs(root->right, sum - root->val, vec, res);
            vec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        vector<int> vec;
        dfs(root, sum, vec, res);
        return res;
    }
};