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
	bool hasSum(int x, TreeNode *p, int sum) {
		if (p == NULL) return false;
		if (p->left == NULL && p->right == NULL) {
			return (x + p->val == sum);
		}
		return hasSum(x + p->val, p->left, sum) 
			|| hasSum(x + p->val, p->right, sum);
	}
    bool hasPathSum(TreeNode *root, int sum) {
    	return hasSum(0, root, sum);
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
	cout<<s.hasPathSum(&n1, 7);
}