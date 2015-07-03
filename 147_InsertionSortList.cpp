// 147 Insertion Sort List
// Sort a linked list using insertion sort.

// Hide Tags Linked List Sort


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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        p->next = new ListNode(head->val);
        head = head->next;
        while(head) {
            p = pHead;
            while(p->next && p->next->val < head->val) {
                p = p->next;
            }
            ListNode* q = p->next;
            p->next = new ListNode(head->val);
            p->next->next = q;
            head = head->next;
        }
        return pHead->next;
    }
};