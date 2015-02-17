#include <iostream>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	return !nodeStack.empty(); 
    }

    /** @return the next smallest number */
    int next() {
    	TreeNode *tmp = nodeStack.top();
    	nodeStack.pop();
    	pushLeft(tmp->right);
    	return tmp->val;
    }
private:
	stack<TreeNode*> nodeStack;
	void pushLeft(TreeNode *node) {
		while (node != NULL) {
			nodeStack.push(node);
			node = node->left;
		}
	}
};
int main() {
	TreeNode n1(1); TreeNode n2(2); TreeNode n3(3);
	TreeNode n4(4); TreeNode n5(5); TreeNode n6(6);
	n3.left = &n2; n3.right = &n5; n2.left = &n1;
	n5.left = &n4; n5.right = &n6;
	BSTIterator i = BSTIterator(&n3);
	while (i.hasNext()) {
		cout<<i.next();
	}
}