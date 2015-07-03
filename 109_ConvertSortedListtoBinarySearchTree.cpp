// 109 Convert Sorted List to Binary Search Tree 
// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);  //Caution, be careful with the case that there is only one node in the list
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* prev = slow;
		while(fast && fast->next) {
			prev = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		fast = slow->next;
		root->right = sortedListToBST(fast);
		prev->next = NULL;
		root->left = sortedListToBST(head);
		return root;
    }
};