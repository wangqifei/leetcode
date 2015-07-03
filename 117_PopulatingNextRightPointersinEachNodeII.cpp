// 117 Populating Next Right Pointers in Each Node II
// Follow up for problem "Populating Next Right Pointers in Each Node".

// What if the given tree could be any binary tree? Would your previous solution still work?

// Note:

// You may only use constant extra space.
// For example,
// Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* curr = root;
        TreeLinkNode* head = NULL;
        TreeLinkNode* prev = NULL;
        while(curr) {
            while(curr) {
                if(curr->left) {
                    if(head == NULL) head = curr->left;
                    if(prev) {
                        prev->next = curr->left;
                        prev = prev->next;
                    }
                    else prev = curr->left;
                }
                if(curr->right) {
                    if(head == NULL) head = curr->right;
                    if(prev) {
                        prev->next = curr->right;
                        prev = prev->next;
                    }
                    else prev = curr->right;
                }
                curr = curr->next;
            }
            curr = head;
            head = NULL;
            prev = NULL;
        }
    }
};