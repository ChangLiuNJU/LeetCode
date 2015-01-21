#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) {
        	return result;
        }
       	vector<int> vl = inorderTraversal(root->left);
       	vector<int> vr = inorderTraversal(root->right);
       	result.insert(result.end(), vl.begin(), vl.end());
        result.push_back(root->val);
        result.insert(result.end(), vr.begin(), vr.end());
        return result;
    }
};

int main() {
	Solution s;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	n1.right = &n2;
	n2.left = &n3;

	vector<int> result = s.inorderTraversal(&n1);
	for (int i = 0; i < result.size(); i++) {
		cout<<result[i]<<endl;
	}
	return 0;
}