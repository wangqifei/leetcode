// 138 Copy List with Random Pointer
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //this algorithm use a queue to do the BFS, but for linkedlist, it is not necessary to use BFS!!!
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        queue<RandomListNode*> q;
        q.push(head);
        mp[head] = new RandomListNode(head->label);
        while(q.empty() == false) {
            RandomListNode* node = q.front();
            q.pop();
            if(node->next) {
                if(mp.find(node->next) == mp.end()) {
                    mp[node->next] = new RandomListNode(node->next->label);
                }
                mp[node]->next = mp[node->next];
            }
            if(node->random) {
                if(mp.find(node->random) == mp.end()) {
                    mp[node->random] = new RandomListNode(node->random->label);
                }
                mp[node]->random = mp[node->random];
            }
            if(node->next) q.push(node->next);
        }
        return mp[head];
    }
private:
    unordered_map<RandomListNode*, RandomListNode*> mp;

    //this solution is more straightforward and easy to understand
    RandomListNode *copyRandomList2(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode* p = head;
        RandomListNode* pHead = new RandomListNode(0);
        RandomListNode* q = pHead;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        while(p) {
            RandomListNode* r = new RandomListNode(p->label);
            q->next = r;
            mp[p] = r;
            p = p->next;
            q = q->next;
        }
        p = head;
        q = pHead->next;
        while(p) {
            if(p->random) {
                q->random = mp[p->random];
            }
            p = p->next;
            q = q->next;
        }
        return pHead->next;
    }
};