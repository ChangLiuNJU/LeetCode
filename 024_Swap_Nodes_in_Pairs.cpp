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
    ListNode *swapPairs(ListNode *head) {
    	if (head == NULL || head->next == NULL) {
    		return head;
    	}
    	ListNode *pre_p = NULL;
    	ListNode *p = head;
    	ListNode *q = p->next;
    	while (p != NULL && q != NULL) {
    		if (pre_p == NULL) {
    			p->next = q->next;
    			q->next = p;
    			head = q;
    		} else {
    			pre_p->next = q;
    			p->next = q->next;
    			q->next = p;
    		}
    		pre_p = p;
    		p = p->next;
    		if (p != NULL) {
    			q = p->next;
    		}
    	}
    	return head;
    }
};

int main() {
	Solution s;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next = &n2; 
	// n2.next = &n3;
	// n3.next = &n4;
	ListNode *p = s.swapPairs(NULL);
	while (p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	return 0;
}