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
    ListNode *detectCycle(ListNode *head) {
    	if (head == NULL) return NULL;
    	ListNode *p1 = head;
    	ListNode *p2 = head;
    	ListNode *meet = NULL;
    	bool hasCycle = false;
    	while (p1->next != NULL && p2->next != NULL && p2->next->next != NULL) {
    		p1 = p1->next;
    		p2 = p2->next->next;
    		if (p1 == p2) {
    			meet = p1;
    			hasCycle = true;
    			break;
    		}
    	}
    	if (!hasCycle) return NULL;
    	p1 = head;
    	p2 = meet;
    	while (p1 != p2) {
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    	return p2;
    }
};
int main() {
	Solution s;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n2;
	cout<<s.detectCycle(&n1)->val<<endl;
}