// 112 Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    //BFS solution
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
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
                if(cur_sum == sum && node->left==NULL && node->right == NULL) return true;  //Caution, the node should be the leaf node, not the node in the middle
                qsum.pop();
                
                if(node->left){ 
                    q.push(node->left);
                    qsum.push(cur_sum+node->left->val);
                }
                if(node->right) {
                    q.push(node->right);
                    qsum.push(cur_sum+node->right->val);
                }
            }
        }
        return false;
    }

    //DFS v1
    bool dfs(TreeNode* root, int prev_sum, int sum) {
        if(prev_sum+root->val == sum && root->left == NULL && root->right == NULL) return true;
        if(prev_sum+root->val != sum || root->left || root->right) {
            if(root->left && dfs(root->left, prev_sum+root->val, sum)) return true;
            if(root->right && dfs(root->right, prev_sum+root->val, sum)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        return dfs(root, 0, sum);
    }

    //DFS v2
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false; //Caution, the following code refers to the field root->left and root->right, we need to make sure if root is a valid node that it has left and right children to be accessed
        if(root->left == NULL && root->right == NULL && root->val == sum) return true;
        if(root->left && hasPathSum(root->left, sum-root->val)) return true;
        if(root->right && hasPathSum(root->right, sum-root->val)) return true;
        return false;
    }
};