// 203 Remove Linked List Elements
// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

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
 #include <iostream>
 using namespace::std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* p = pHead;
        while(p->next) {
            if(p->next->val == val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;  //Caution, if p->next->val == val, p should not go to p->next since the new p->next->val has not been tested yet
            }
        }
        return pHead->next;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {1};
    int len = 1;
    int val = 1;
    LinkedList myLinkedList;
    ListNode* head = myLinkedList.buildLinkedList(A, len);
    Solution mySolution;
    ListNode* res = mySolution.removeElements(head, val);
    myLinkedList.printLinkedList(res);
    return 0;
}