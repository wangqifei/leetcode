// 114 Flatten Binary Tree to Linked List 
// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// click to show hints.

// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        while(root) {
            if(root->left) {
                TreeNode* nr = root->right;
                TreeNode* nl = root->left;
                while(nl->right != NULL) nl = nl->right;
                root->right = root->left;
                nl->right = nr;
                root->left = NULL;
            }
            root = root->right;
        }
    }

    //DFS recursive solution
    void flatten(TreeNode* root) {
        dfs(root);
    }
    TreeNode* dfs(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        TreeNode* node = root;
        if(left) {
            root->left = NULL;
            root->right = left;
            while(node->right) node = node->right;
        }
        node->right = right;
        return root;
    }
};