// 173 Binary Search Tree Iterator
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Hide Tags Tree Stack


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Caution, the iterator need to traverse the whol BST in the corrected order
 //the iterator should start from the minimum element in BST and ended by the largest element in the BST
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* temp = root;
        while(temp) {
            st.push(temp);
            temp = temp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.empty() == false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* curr = st.top();
        int res = curr->val;
        st.pop();
        curr = curr->right;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        return res;
    }
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */