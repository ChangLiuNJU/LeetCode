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
	int getSum(int x, TreeNode *p) {
		if (p == NULL) return 0;
		if (p->left == NULL && p->right == NULL) {
			return x * 10 + p->val;
		}
		int result = 0;
		if (p->left != NULL) {
			result += getSum(x * 10 + p->val, p->left);
		}
		if (p->right != NULL) {
			result += getSum(x * 10 + p->val, p->right);
		}
		return result;
	}
    int sumNumbers(TreeNode *root) {
    	return getSum(0, root);
    }
};
int main() {
	Solution s;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = &n5;
	cout<<s.sumNumbers(&n1);
}