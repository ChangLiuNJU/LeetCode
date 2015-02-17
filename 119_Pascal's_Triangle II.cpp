#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	rowIndex++;
    	vector<vector<int> > result;
    	vector<int> tmp;
 		if (rowIndex == 0) return tmp;
 		rowIndex--;
    	for (int i = 0; i < rowIndex; i++) {
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
    	return result[rowIndex];
    }
};
int main() {
	Solution s;
	vector<int> v = s.getRow(3);
	for (auto i:v) {
		cout<<i<" ";
	}
}