#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	int n = matrix.size();
    	//each layer
    	for (int l = 0; l < n/2; l++) {
    		for (int k = 0; k < n-2*l-1; k++) {
    			int tmp = matrix[l][l+k];
    			matrix[l][l+k]			= matrix[n-l-k-1][l];
    			matrix[n-l-k-1][l] 		= matrix[n-l-1][n-l-k-1];
    			matrix[n-l-1][n-l-k-1] 	= matrix[l+k][n-l-1];
    			matrix[l+k][n-l-1]		= tmp;
    		}
    	}
    }
};
int main() {
	Solution s;
	int a[] = {0,1,2};
	vector<int> v1(a,a+3);
	int b[] = {3,4,5};
	vector<int> v2(b,b+3);
	int c[] = {6,7,8};
	vector<int> v3(c,c+3);
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	s.rotate(v);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}