#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > result(n, vector<int>(n));
    	int x = 1;
    	for (int l = 0; l < (n + 1) / 2; l++) {
    		int start = l;
    		int end = n - l - 1;
    		if (start == end) {
    			result[start][start] = x;
    			break;
    		}
    		for (int i = start; i <= end; i++) {
    			result[start][i] = x;
    			x++;
  			}
  			for (int i = start + 1; i <= end - 1; i++) {
  				result[i][end] = x;
  				x++;
  			}
  			for (int i = end; i >= start; i--) {
  				result[end][i] = x;
  				x++;
  			}
  			for (int i = end - 1; i >= start + 1; i--) {
  				result[i][start] = x;
  				x++;
  			}
    	}
    	return result;
    }
};
int main() {
	Solution s;
	vector<vector<int> > v = s.generateMatrix(0);
	for (auto i:v) {
		for (auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}