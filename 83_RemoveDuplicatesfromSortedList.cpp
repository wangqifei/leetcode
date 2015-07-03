// 83 Remove Duplicates from Sorted List
// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        head = pHead;
        ListNode* p = head->next;
        while(p->next) {
            if(head->next->val != p->next->val) {
                head->next = p;
                head = head->next;
                p = p->next;
            }
            else {
                p = p->next;
            }
        }
        head->next = p;
        return pHead->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        head = pHead;
        ListNode* p = head->next;
        while(p->next) {
            if(head->next->val == p->next->val) {
                head->next = p->next;
            }
            else {
                head = head->next;
            }
            p = p->next;
        }
        return pHead->next;
    }
};