// 206 Reverse Linked List
// Reverse a singly linked list.

// click to show more hints.

// Hint:
// A linked list can be reversed either iteratively or recursively. Could you implement both?

// Hide Tags Linked List


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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        while(head->next) {
            ListNode* p = pHead->next;
            pHead->next = head->next;
            head->next = head->next->next;
            pHead->next->next = p;
        }
        return pHead->next;
    }

    ListNode* reverseList2(ListNode* head) {
        if(head == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr;
        while(head) {
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }

    ListNode* reverseList3(ListNode* head) {
        if(head == NULL) return head;
        ListNode* p = reverseList3(head->next);
        if(p == NULL) return head; //Caution!!! prevent error if there is only one node
        ListNode* q = p;
        while(q->next) {
            q = q->next;
        }
        q->next = head;
        head->next = NULL;
        return p;
    }
};