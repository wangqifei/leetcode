// 23 Merge k Sorted Lists
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <vector>
 #include <queue>
 #include <iostream>
 using namespace::std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    struct cmp
    {
        bool operator ()(const ListNode *a, const ListNode *b)
        {
                return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode* pHead = new ListNode(0);
        ListNode* p = pHead;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i]) q.push(lists[i]);
        }
        while(q.empty() == false)
        {
            ListNode* curr = q.top();
            q.pop();
            p->next = curr;
            p = p->next;
            if(curr->next)
            {
                q.push(curr->next);
            }
        }
        return pHead->next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}