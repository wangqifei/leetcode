// 102 Binary Tree Level Order Traversal
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
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
 #include <vector>
 #include <queue>
 #include <iostream>
 #include "BinaryTree.h"
 using namespace::std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> vec;
        while(q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                if(vec.empty() == false) {
                    res.push_back(vec);
                    vec.clear();
                    q.push(NULL);
                }
            }
            else {
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "1";
    vector<char> tree_vec(s.begin(), s.end());
    BinaryTree BinaryTreeTest;
    TreeNode* root = BinaryTreeTest.BuildBinaryTree(tree_vec);
    Solution mySolution;
    vector<vector<int> > res = mySolution.levelOrder(root);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}