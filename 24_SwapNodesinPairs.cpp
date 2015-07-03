// 24 Swap Nodes in Pairs 
// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        head = pHead;
        ListNode* p = head->next;
        while(p && p->next)
        {
            p = p->next->next;
            ListNode* q = head->next;
            head->next = head->next->next;
            head->next->next = q;
            q->next = p;
            head = head->next->next;
        }
        return pHead->next;
    }
};