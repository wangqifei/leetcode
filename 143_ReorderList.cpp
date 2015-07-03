// 143 Reorder List
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

// Hide Tags Linked List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include "LinkedList.h"
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = slow->next;
        while(p->next) {
            ListNode* q = slow->next;
            slow->next = p->next;
            p->next = p->next->next;
            slow->next->next = q;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        while(slow->next && fast) {
            p = slow->next;
            ListNode* q = fast->next;
            slow->next = fast;
            fast->next = p;
            slow = p;
            fast = q;
        }
        if(fast) 
            slow->next = fast;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int A[] = {1,2,3};
    int n = 3;
    LinkedList myLinkedList;
    ListNode* head = myLinkedList.buildLinkedList(A, n);
    Solution mySolution;
    mySolution.reorderList(head);
    myLinkedList.printLinkedList(head);
    return 0;
}