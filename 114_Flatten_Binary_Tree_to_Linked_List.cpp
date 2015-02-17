#include <iostream>
using namespace std;

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void flatten(TreeNode *root) {
    	if (root == NULL) return;
    	TreeNode *l = root->left;
    	TreeNode *r = root->right;
    	flatten(l);
    	flatten(r);
    	if (l == NULL) {
    		root->right = r;
            root->left = NULL;
    	} else {
    		root->right = l;
            root->left = NULL;
    		while (l->right != NULL) { 
    			l = l->right;
    		}
    		l->right = r;
    	}
    }
};

int main() {
	Solution s;
	TreeNode n1(1);TreeNode n2(2);TreeNode n3(3);
	TreeNode n4(4);TreeNode n5(5);TreeNode n6(6);
	n1.left = &n2; 
    n1.right = &n5;
	// n2.left = &n3; n2.right = &n4;
	// n5.left = &n6;

	s.flatten(&n1);
	TreeNode *p = &n1;
	while (p != NULL) {
		cout<<p->val<<" ";
        p = p->right;
	}

}