// Unique Binary Search Trees II
// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    vector<TreeNode*> generateSubTree(int st, int ed) {
        vector<TreeNode*> res;
        if(st > ed) {
            res.push_back(NULL);
            return res;
        }
        if(st == ed) {
            res.push_back(new TreeNode(st));
            return res;
        }
        for(int i = st; i <= ed; ++i) {
            vector<TreeNode*> leftSubTree = generateSubTree(st, i-1);
            vector<TreeNode*> rightSubTree = generateSubTree(i+1, ed);
            for(auto left_node : leftSubTree) {
                for(auto right_node : rightSubTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_node;
                    root->right = right_node;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateSubTree(1, n);
    }
};