// 160 Intersection of Two Linked Lists
// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// Credits:
// Special thanks to @stellari for adding this problem and creating all test cases.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        ListNode* endA = NULL; //Caution!!! we need the tail to know if there is no intersection
        ListNode* endB = NULL;
        while(true) {
            if(p1 == p2) return p1;
            if(p1->next) p1 = p1->next;
            else {
                if(endA == NULL) { 
                    endA = p1;
                    p1 = headB;
                }
                else {
                    return NULL;
                }
            }
            if(p2->next) p2 = p2->next;
            else {
                if(endB == NULL) {
                    endB = p2;
                    p2 = headA;
                }
                else {
                    return NULL;
                }
            }
        }
    }
};