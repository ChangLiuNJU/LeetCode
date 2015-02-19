#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p = headA;
		ListNode *q = headB;
		
		while (p != NULL && q != NULL) {
			if (p == q) return p;
			p = p->next;
			q = q->next;
		}
		if (p == NULL) {
			p = headB;
			while (q != NULL) {
				p = p->next;
				q = q->next;
			}
			q = headA;
			while (p != NULL) {
				if (p == q) return p;
				p = p->next;
				q = q->next;
			}
		} else if (q == NULL) {
			q = headA;
			while (p != NULL) {
				p = p->next;
				q = q->next;
			}
			p = headB;
			while (q != NULL) {
				if (p == q) return p;
				p = p->next;
				q = q->next;
			}
		}
		return NULL;
    }
};

int main() {
	Solution s;
	ListNode n1(1); ListNode n2(2); ListNode n3(3);
	ListNode n4(4); ListNode n5(5); ListNode n6(6);
	ListNode n7(7);
	n1.next = &n2; n2.next = &n6; n6.next = &n7;
	n3.next = &n4; n4.next = &n5; n5.next = &n6;
	cout<<s.getIntersectionNode(&n1, &n3)->val<<endl;
}