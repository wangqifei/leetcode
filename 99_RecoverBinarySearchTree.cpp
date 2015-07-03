//  99 Recover Binary Search Tree
// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
private:
	TreeNode* prev;
	TreeNode* first;
	TreeNode* second;
public:
    void inOrder(TreeNode* root)
	{
		if(root == NULL)
			return;
		if(root->left) inOrder(root->left);
		if(prev == NULL) {
			prev = root;
		}
		else {
			if(prev->val > root->val) {
				if(first == NULL) {
					first = prev;
				}
				second = root;
			}
			prev = root;
		}
		if(root->right) inOrder(root->right);
	}
    void recoverTree(TreeNode* root) {
        prev = NULL;
		first = NULL;
		second = NULL;
		inOrder(root);
		if(first && second) {
		    int temp = first->val;
		    first->val = second->val;
		    second->val = temp;
		}
    }
};