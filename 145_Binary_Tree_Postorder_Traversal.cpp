#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode *root) {
   		vector<int> result;
   		if (root == NULL) return result;
   		stack<TreeNode*> s;
   		s.push(root);
   		while (!s.empty()) {
   			TreeNode *top = s.top();
   			result.push_back(top->val);
   			s.pop();
   		   	if (top->left) {
   				s.push(top->left);
   			}	
   			if (top->right) {
   				s.push(top->right);
   			}
   		}
   		reverse(result.begin(), result.end());
   		return result;
    }
};

int main() {
	Solution s;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	n1.right = &n2;
	n1.left = &n3;

	vector<int> result = s.postorderTraversal(&n1);
	for (int i = 0; i < result.size(); i++) {
		cout<<result[i]<<endl;
	}
	return 0;
}