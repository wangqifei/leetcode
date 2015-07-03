// 103 Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
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
 #include <algorithm>
 #include "BinaryTree.h"
 using namespace::std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool order = true;
        vector<int> vec;
        while(q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                if(vec.empty() == false) {
                    cout<<order<<endl;
                    if(order) {
                        res.push_back(vec);
                        order = false; //Caution, bool is a one byte vaiable. if order = 1, ~order = 11111110
                    }
                    else {
                        reverse(vec.begin(), vec.end());
                        res.push_back(vec);
                        order = true;
                    }
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
    string s = "123";
    vector<char> tree_vec(s.begin(), s.end());
    BinaryTree BinaryTreeTest;
    TreeNode* root = BinaryTreeTest.BuildBinaryTree(tree_vec);
    Solution mySolution;
    vector<vector<int> > res = mySolution.zigzagLevelOrder(root);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}