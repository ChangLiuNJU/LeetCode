#include <iostream>
#include <stdlib.h>
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
    bool isBalanced(TreeNode *root) {
    	if (root == NULL) return true;
    	return isBalanced(root->left) 
    		&& isBalanced(root->right)
    		&& (abs(getDepth(root->left) - getDepth(root->right)) < 2);
    }
private:
	int getDepth(TreeNode *root) {
		if (root == NULL) 
			return 0;
		return max(getDepth(root->left),getDepth(root->right)) + 1;
	}
};

int main() {
	Solution s;
	TreeNode n1(0);
	TreeNode n2(0);
	TreeNode n3(0);
	TreeNode n4(0);
	n1.left = &n2;
	n2.left = &n4;
	cout<<s.isBalanced(&n1);
}