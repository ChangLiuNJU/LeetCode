#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> v;
  		addPar(v, "", n, 0);
    	return v;
    }
    void addPar(vector<string> &v, string s, int l, int r) {
    	if (l == 0 && r == 0) {
    		v.push_back(s);
    		return;
    	}
    	if (l > 0) {
    		addPar(v, s + "(", l-1, r+1);
    	}
    	if (r > 0) {
    		addPar(v, s + ")", l, r-1);
    	}
    }
};
int main() {
	Solution s;
	vector<string> v = s.generateParenthesis(3);
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" "<<endl;
	}
	cout<<endl;
	return 0;
}