#include <iostream>
using namespace std;

//Definition for singly-linked list.
	struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) {
        	return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != NULL) {
        	if (q->val == p->val) {
        		p->next = q->next;
        		q = q->next;
        	} else {
        		p = p->next;
        		q = q->next;
        	}
        }
        return head;
    }
};

int main() {
	Solution s;
	ListNode n1(1);
	ListNode n2(1);
	ListNode n3(2);
	ListNode n4(3);
	ListNode n5(3);
	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
	ListNode *head = s.deleteDuplicates(&n1);
	while (head != NULL) {
		cout<<head->val<< " ";
		head = head->next;
	}
	return 0;
}