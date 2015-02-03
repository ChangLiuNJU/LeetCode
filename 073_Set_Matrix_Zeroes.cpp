#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	int firstZeroRow = -1;
    	for (int i = 0; i < matrix.size(); i++) {
    		bool isHasZero = false;
    		for (int j = 0; j < matrix[i].size(); j++) {
    			if (matrix[i][j] == 0) {
    				isHasZero = true;
    				if (firstZeroRow == -1) {
    					firstZeroRow = i;
    					for (int k = 0; k < matrix[i].size(); k++) {
    						matrix[i][k] = (matrix[i][k] == 0); 
    					}
    					break;
    				} else {
    					matrix[firstZeroRow][j] = 1;
    				}
    			}
    		}
    		if (isHasZero && i != firstZeroRow) {
    			for (int j = 0; j < matrix[i].size(); j++)
    				matrix[i][j] = 0;
    		}
    	}
    	if (firstZeroRow != -1) {
	    	for (int j = 0; j < matrix[0].size(); j++) {
	    		if (matrix[firstZeroRow][j] == 1) {
	    			for (int i = 0; i < matrix.size(); i++) {
	    				matrix[i][j] = 0;
	    			}
	    		}
	    	}
	    }
    }
};
int main() {
	Solution s;
	vector<vector<int> > v = {{-1,2,3}};
	s.setZeroes(v);
	for (auto x : v) {
		for (auto y : x) {
			cout<<y<<" ";
		}
		cout<<endl;
	}
}