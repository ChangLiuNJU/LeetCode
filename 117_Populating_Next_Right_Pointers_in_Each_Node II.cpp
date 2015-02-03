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
        TreeLinkNode *nextHead = NULL;
        TreeLinkNode *lead = NULL;
        TreeLinkNode *cur = root;

        while (cur != NULL) {
            while (cur != NULL) {
                if (cur->left != NULL) {
                    if (lead == NULL) {
                        nextHead = cur->left;
                    } else {
                        lead->next = cur->left;
                    }
                    lead = cur->left;
                }
                if (cur->right != NULL) {
                    if (lead == NULL) {
                        nextHead = cur->right;
                    } else {
                        lead->next = cur->right;
                    }
                    lead = cur->right;
                }
                cur = cur->next;
            }
            cur = nextHead;
            nextHead = NULL;
            lead = NULL;
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