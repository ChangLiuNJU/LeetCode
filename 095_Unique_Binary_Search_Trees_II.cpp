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
    vector<TreeNode *> generateTrees(int n) {
    	if (n == 0) {
    		vector<TreeNode *> result;
    		result.push_back(NULL);
    		return result;
    	}
    	return generate(1, n);
    }
private:
	vector<TreeNode *> generate(int s, int t) {
		vector<TreeNode *> result;
		if (s > t) return result; 
		for (int i = s; i <= t; i ++) {
			vector<TreeNode *> l = generate(s, i - 1);
			vector<TreeNode *> r = generate(i + 1, t);
			if (l.size() == 0 && r.size() == 0) {
				TreeNode *node = new TreeNode(i);
				result.push_back(node);
			} else if (l.size() == 0) {
				for (int k = 0; k < r.size(); k++) {
					TreeNode *node = new TreeNode(i);
					node->right = r[k];
					result.push_back(node);
				}
			} else if (r.size() == 0) {
				for (int k = 0; k < l.size(); k++) {
					TreeNode *node = new TreeNode(i);
					node->left = l[k];
					result.push_back(node);
				}
			} else {
				for (int j = 0; j < l.size(); j++) {
					for (int k = 0; k < r.size(); k++) {
						TreeNode *node = new TreeNode(i);
						node->left = l[j];
						node->right = r[k];
						result.push_back(node);
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<TreeNode *> v = s.generateTrees(2);
	cout<<v.size()<<endl;

}