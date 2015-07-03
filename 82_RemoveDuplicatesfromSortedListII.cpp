// 82 Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.


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
        bool flag = false;
        while(p->next) {
            if(p->next->val != head->next->val) {
                if(flag == true) {
                    head->next = p->next;
                    flag = false;
                }
                else {
                    head->next = p;
                    head = head->next;
                }
                p = p->next;
            }
            else {
                p = p->next;
                flag = true;
            }
        }
        if(flag == true) {
            head->next = NULL;
        }
        return pHead->next;
    }
};