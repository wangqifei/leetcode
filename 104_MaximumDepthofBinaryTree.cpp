// 104 Maximum Depth of Binary Tree
// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
	//DFS solution
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
    //BFS solution
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int res = 1;
        while(q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            if(q.empty() == false && node == NULL) {
                q.push(NULL);
                res++;
            }
            if(node && node->left) q.push(node->left);
            if(node && node->right) q.push(node->right);
        }
        return res;
    }

    int maxDepth(TreeNode* root) {
    	if(root == NULL) return 0;
    	queue<TreeNode*> q;
    	q.push(root);
    	int res = 0;
    	while(q.empty()==false) {
    		int sz = q.size();
    		if(sz) res++;
    		for(int i = 0; i < sz; ++i) {
    			TreeNode* node = q.front();
    			q.pop();
    			if(node->left) q.push(node->left);
    			if(node->right) q.push(node->right);
    		}
    	}
    	return res;
    }
};