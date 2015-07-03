// 101 Symmetric Tree
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;
        return check(left->left, right->right) && check(right->left, left->right);
    }

    bool isSymmetric2(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> ql;
        queue<TreeNode*> qr;
        ql.push(root->left);
        qr.push(root->right);
        while(ql.empty()==false && qr.empty()==false) {
            TreeNode* ln = ql.front();
            TreeNode* rn = qr.front();
            ql.pop();
            qr.pop();
            if(ln == NULL && rn == NULL) continue;
            if(ln == NULL || rn == NULL) return false;
            if(ln->val != rn->val) return false;
            ql.push(ln->left);
            ql.push(ln->right);
            qr.push(rn->right);
            qr.push(rn->left);
        }
        return true;
    }
};