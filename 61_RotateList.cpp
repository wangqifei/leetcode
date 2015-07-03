// 61 Rotate List
// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* endNode = pHead;
        int cnt = 0;
        while(endNode->next) {
            endNode = endNode->next;
            cnt++;
        }
        k = k%cnt;
        if(k == 0) return head;
        ListNode* midNode = pHead;
        int n = cnt-k;
        while(n>0) {
            midNode = midNode->next;
            n--;
        }
        pHead->next = midNode->next;
        endNode->next = head;
        midNode->next = NULL;
        return pHead->next;
    }
};