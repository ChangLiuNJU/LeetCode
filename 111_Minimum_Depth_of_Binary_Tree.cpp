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
    int minDepth(TreeNode *root) {
    	if (root == NULL) return 0;
    	if (root->left == NULL) {
    		return minDepth(root->right) + 1;
    	} else if (root->right == NULL) {
    		return minDepth(root->left) + 1;
    	}
    	return min(minDepth(root->left), minDepth(root->right)) + 1;

    }
};

int main() {
	Solution s;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n3.left = &n6;
	n4.left = &n5;
	cout<<s.minDepth(&n1);
}