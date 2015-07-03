// 129 Sum Root to Leaf Numbers
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25.

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
    //dfs solution, recursion
    void dfs(TreeNode* root, int cur, int& res)
    {
        if(root->left == NULL && root->right == NULL)
        {
            cur = cur*10 + root->val;
            res += cur;
            return;
        }
        if(root->left) dfs(root->left, cur*10+root->val, res);
        if(root->right) dfs(root->right, cur*10+root->val, res);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int cur = 0;
        int res = 0;
        dfs(root, cur, res);
        return res;
    }

    //iterative bfs solution
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> q;
        queue<int> qsum;
        q.push(root);
        qsum.push(root->val);
        while(q.empty() == false) {
            int len = q.size();
            for(int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int cur_sum = qsum.front();
                qsum.pop();
                if(node->left == NULL && node->right == NULL) {
                    res += cur_sum;
                }
                if(node->left) {
                    q.push(node->left);
                    qsum.push(cur_sum*10+node->left->val);
                }
                if(node->right) {
                    q.push(node->right);
                    qsum.push(cur_sum*10+node->right->val);
                }
            }
        }
        return res;
    }
};