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
	bool isEqual(TreeNode *nl, TreeNode *nr) {
		if (nr == NULL && nl == NULL) return true;
		if (nr == NULL || nl == NULL) return false;
		if (nl->val != nr->val) return false;
		return isEqual(nl->left, nr->right) 
			&& isEqual(nl->right, nr->left);
	}
    bool isSymmetric(TreeNode *root) {
    	if (root == NULL) return true;
    	return isEqual(root->left, root->right);
    }
};

int main() {
	Solution s;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(2);
	TreeNode n4(3);
	TreeNode n5(3);
	TreeNode n6(4);
	TreeNode n7(4);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n6;
	n3.left = &n7; n3.right = &n5;
	cout<<s.isSymmetric(&n1);
}