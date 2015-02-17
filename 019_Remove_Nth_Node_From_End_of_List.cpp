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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if (head == NULL) return head;
    	ListNode prehead(-1);
    	prehead.next = head;
    	ListNode *end = &prehead;
    	ListNode *prev = &prehead;
    	for (int i = 0; i < n; i++)
    		end = end->next;
    	while (end->next != NULL) {
    		prev = prev->next;
    		end = end->next;
    	}
    	prev->next = prev->next->next;
    	return prehead.next;
    }
};

int main() {
	Solution s;
	ListNode n1(1);ListNode n2(2);ListNode n3(3);
	ListNode n4(4);ListNode n5(5);ListNode n6(6);

	n1.next = &n2; n2.next = &n3; n3.next = &n4;
	n4.next = &n5; n5.next = &n6;

	ListNode *p = s.removeNthFromEnd(&n1, 1);
	while (p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}