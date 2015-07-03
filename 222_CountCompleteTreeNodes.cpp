// 222 Count Complete Tree Nodes
// Given a complete binary tree, count the number of nodes.

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(q.empty()==false) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                res++;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }

    int countNodes2(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int nl = 1;
        int nr = 1;
        while(l) {l = l->left; nl++;}
        while(r) {r = r->right; nr++;}
        if(nl==nr) return pow(2, nl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int countNodes3(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        int leftLevel = 1;
        int rightLevel = 1;
        while(leftChild) { leftChild = leftChild->left; leftLevel++; }
        while(rightChild) { rightChild = rightChild->right; rightLevel++;}
        if(leftLevel == rightLevel) return (1<<leftLevel)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};