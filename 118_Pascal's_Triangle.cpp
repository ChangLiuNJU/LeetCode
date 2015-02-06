#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > result;
 		if (numRows == 0) return result;
 		numRows--;
    	for (int i = 0; i < numRows; i++) {
    		vector<int> tmp;
    		tmp.push_back(1);
    		for (int j = 1; j < i + 1; j++) {
    			tmp.push_back(result[i-1][j-1] + result[i-1][j]);
    		}
    		tmp.push_back(1);
    		result.push_back(tmp);
    	}
    	vector<int> v = {1};
    	result.insert(result.begin(), v);
    	return result;
    }
};

int main() {
	Solution s;
	vector<vector<int> > v = s.generate(0);
	for (auto i:v) {
		for (auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}