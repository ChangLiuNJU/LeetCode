#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
  	TreeNode *left;
   	TreeNode *right;
   	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > tree;
    	if (root == NULL) {
    		return tree;
    	}
    	queue<TreeNode> q;
    	q.push(*root);
    	while (!q.empty()) {
    		int size = q.size();
    		vector<int> v;
    		for (int i = 0; i < size; i ++) {
    			TreeNode node = q.front();
    			q.pop();
    			if (node.left != NULL) {
    				q.push(*(node.left));
    			}
 				if (node.right != NULL) {
 					q.push(*(node.right));
 				}	
 				v.push_back(node.val);
    		}
    		tree.push_back(v);
    	}
    	return tree;
    }
};
void printTree(vector<vector<int> > tree) {
	vector<vector<int> >::iterator i;
	for (i = tree.begin(); i != tree.end(); i++) {
		vector<int>::iterator j;
		for (j = (*i).begin(); j != (*i).end(); j++) {
			cout<<*j;
		}
		cout<<endl;
	}	
}
int main() {
	TreeNode t3 	= TreeNode(3);
	TreeNode t9 	= TreeNode(9);	
	TreeNode t20 	= TreeNode(20);
	TreeNode t15 	= TreeNode(15);
	TreeNode t7 	= TreeNode(7);
	t3.left = &t9;
	t3.right = &t20;
	t20.left = &t15;
	t20.right = &t7;
	Solution s;
	// s.levelOrderBottom(&t3);
	printTree(s.levelOrder(&t3));
	return 0;
}
