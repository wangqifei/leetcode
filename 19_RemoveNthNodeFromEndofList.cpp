// 19 Remove Nth Node From End of List 
// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        head = pHead;
        ListNode* p = head;
        int i = 0;
        while(p->next && i < n){
            p = p->next; 
            i++;
        }
        while(p->next){
            head = head->next;
            p = p->next;
        }
        head->next = head->next->next;
        return pHead->next;
    }
};