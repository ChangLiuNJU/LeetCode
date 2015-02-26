#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	if (head == NULL) return NULL;
    	ListNode *pre_s1 = NULL;
    	ListNode *s1 = head;
    	ListNode *s2 = head;
    	while (s2 != NULL && s2->next != NULL && s2->next->next != NULL) {
    		s2 = s2->next->next;
    		pre_s1 = s1;
    		s1 = s1->next;
    	}
    	TreeNode *t = new TreeNode(s1->val);
    	if (pre_s1 != NULL) {
    		pre_s1->next = NULL;
    		t->left = sortedListToBST(head);
    	}
    	pre_s1 = s1->next;
    	s1->next = NULL;
    	if (pre_s1 != NULL) {
    		t->right = sortedListToBST(pre_s1);
    	}

    	return t;
    }
};

int main() {
	Solution s;
	ListNode n1(1); ListNode n2(2); ListNode n3(3);
	ListNode n4(4); ListNode n5(5);
	n1.next = &n2; 
	n2.next = &n3; n3.next = &n4;
	n4.next = &n5;
	TreeNode *t = s.sortedListToBST(&n1);
	cout<<t->left->val<<endl;
}