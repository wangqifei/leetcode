// 142 Linked List Cycle II
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// Follow up:
// Can you solve it without using extra space?

// Hide Tags Linked List Two Pointers


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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        bool flag = false;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                flag = true;
                break;
            }
        }
        if(flag == false) return NULL;
        slow = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};