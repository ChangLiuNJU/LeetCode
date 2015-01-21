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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	if (l1 == NULL) return l2;
    	if (l2 == NULL) return l1;
    	ListNode *head = l1;
    	ListNode *p = l1;
    	ListNode *q = l2;
    	if (l2->val < l1->val) {
    		head = l2;
    		p = l2;
    		q = l1;
    	}
    	while (p->next != NULL && q != NULL) {
    		if (p->val <= q->val && p->next->val > q->val) {
    			ListNode *tmp = q->next;
    			q->next = p->next;
    			p->next = q;
    			p = p->next;
    			q = tmp;
    		} else {
    			p = p->next;
    		}
    	}
    	while (q != NULL) {
    		p->next = q;
    		p = p->next;
    		q = q->next;
    	}
    	return head;
    }
};
int main() {
	Solution s;
	ListNode n0(0);
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	n1.next = &n3; n3.next = &n4;
	ListNode *p = s.mergeTwoLists(&n1, &n0);
	while (p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	return 0;
}