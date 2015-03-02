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
    ListNode *partition(ListNode *head, int x) {
    	if (head == NULL) return NULL;
 		ListNode *tail = head;
 		while (tail->next != NULL) {
 			tail = tail->next;
 		}
 		ListNode *mark = tail;
 		ListNode *p = head;
 		ListNode *pre = NULL;
 		bool finish = false;
 		while (!finish) {
 			if (p == mark) finish = true;
 			if (p->val >= x) {
 				if (p == head && p != tail) {
 					head = p->next;
 					tail->next = p;
 					p ->next = NULL;
 					tail = tail->next;
 					p = head;
 				} else if (p != tail) {
 					pre->next = p->next;
 					p->next = NULL;
 					tail->next = p;
 					tail = tail->next;
 					p = pre->next;
 				}
 			} else {
 				pre = p;
 				p = p->next;
 			}
 		}
 		return head;
    }
};

int main() {
	Solution s;
	ListNode n1(1); ListNode n2(4); ListNode n3(3);
	ListNode n4(2); ListNode n5(5); ListNode n6(2);
	// n1.next = &n2; 
	// n2.next = &n3; 
	// n3.next = &n4;
	// n4.next = &n5; 
	// n5.next = &n6;
	ListNode *p = s.partition(&n1, 0);
	while (p != NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}