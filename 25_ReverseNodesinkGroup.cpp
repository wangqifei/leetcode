// 25 Reverse Nodes in k-Group
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Caution!!! reverse a linked list
 //h->1->2->3->NULL => h->2->1->3->NULL => h->3->2->1->NULL
 //we need to pointers, one points to h->next, the other one point to 1 for checking stop criterion (1->NULL)
 //another way to reverse a linkedlist http://articles.leetcode.com/2010/04/reversing-linked-list-iteratively-and.html
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        if(k == 0 || k == 1) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        head = pHead;
        ListNode* tempHead;
        ListNode* p;
        ListNode* q;
        int i;
        while(head)
        {
            p = head;
            i = 0;
            while(p && p->next && i < k) //Caution!!! p is used to indicate the last one in the current group. If p->next == NULL, means we have reach the last one and we can stop
            {
                p = p->next;
                i++;
            }
            if(i < k) return pHead->next;
            q = p->next;
            tempHead = head->next;
            while(tempHead->next != q)
            {
                p = head->next;
                head->next = tempHead->next;
                tempHead->next = tempHead->next->next;
                head->next->next = p;
            }
            head = tempHead;
        }
        return pHead->next;
    }
};