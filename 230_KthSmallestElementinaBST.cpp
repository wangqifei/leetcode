// 230 Kth Smallest Element in a BST Total Accepted: 267 Total Submissions: 808 My Submissions Question Solution 
// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

// Hint:

// Try to utilize the property of a BST.
// What if you could modify the BST node's structure?
// The optimal runtime complexity is O(height of BST).

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(node || st.empty() == false) {
            while(node) {
                st.push(node);
                node = node->left;
            }
            if(st.empty() ==  false) {
                node = st.top();
                st.pop();
                k--;
                if(k==0) return node->val;
                node = node->right;
            }
        }
    }
};