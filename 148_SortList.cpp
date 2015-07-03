// 148 Sort List
// Sort a linked list in O(n log n) time using constant space complexity.

// Hide Tags Linked List Sort


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //in this problem, we use merge sort, but not quick sort, because the merge of linkedlist does not require any additional space, moreover, quick sort usually need to go the previous element which is hard for linkedlist
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(head1 && head2) {
            if(head1->val < head2->val) {
                p->next = head1;
                head1 = head1->next;
            }
            else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 == NULL) p->next = head2;
        else if(head2 == NULL) p->next = head1;
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(fast);
        ListNode* res = merge(h1, h2);
        return res;
    }
};