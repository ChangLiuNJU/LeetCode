#include <iostream>
using namespace std;

// Definition for binary tree with next pointer.
	struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == NULL || root->left == NULL || root->right == NULL) {
    		return;
    	}
    	connect(root->left);
    	connect(root->right);
    	root->left->next = root->right;
    	TreeLinkNode* p1 = root->left->right;
    	TreeLinkNode* p2 = root->right->left;
    	while (p1 != NULL && p2 != NULL) {
    		p1->next = p2;
    		p1 = p1->right;
    		p2 = p2->left;
    	}
    }
};

int main() {
	Solution s;
	TreeLinkNode n1(1);
	TreeLinkNode n2(2);
	TreeLinkNode n3(3);
	n1.left = &n2;
	n1.right = &n3;
	s.connect(&n1);
	cout<<n2.next->val;
	return 0;
}