// linked list class
#include <vector>
#include <iostream>
using namespace::std;
struct ListNode
{
	/* data */
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {}
};

class LinkedList
{
public:
	LinkedList() {}
	~LinkedList() {}

	/* data */
	ListNode* buildLinkedList(vector<int> vec) {
		ListNode* head = new ListNode(0);
		ListNode* p = head;
		for(int i = 0; i < vec.size(); ++i) {
			p->next = new ListNode(vec[i]);
			p = p->next;
		}
		return head->next;
	}

	ListNode* buildLinkedList(int A[], int n) {
		ListNode* head = new ListNode(0);
		ListNode* p = head;
		for(int i = 0; i < n && A[i] != '\0'; ++i) {
			p->next = new ListNode(A[i]);
			p = p->next;
		}
		return head->next;
	}

	void printLinkedList(ListNode* head) {
		while(head) {
			cout<<head->val<<" ";
			head = head->next;
		}
		cout<<endl;
	}
};