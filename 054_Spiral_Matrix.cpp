#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> result;
    	if (matrix.size() == 0 || matrix[0].size() == 0) return result;
    	int m = matrix.size();
    	int n = matrix[0].size();
    	for (int l = 0; l < (m + 1) / 2; l++) {
    		int up = l;
    		int down = m - l - 1;
    		int left = l;
    		int right = n - l - 1;
    		if (left == right) {
    			for (int i = up; i <= down; i++)
    				result.push_back(matrix[i][left]);
    			break;
    		}
    		if (left > right) break;
    		for (int i = left; i <= right; i++)
    			result.push_back(matrix[up][i]);
    		if (up < down) {
    			for (int i = up + 1; i <= down - 1; i++) 
    				result.push_back(matrix[i][right]);
    			for (int i = right; i >= left; i--)
    				result.push_back(matrix[down][i]);
    			if (left < right) {
    				for (int i = down - 1; i >= up + 1; i--)
    					result.push_back(matrix[i][left]);
    			}
    		}
    	}
    	return result;
    }
};
int main() {
	Solution s;
	vector<vector<int> > matrix = {	{1, 11},
									{2, 12},
									{3, 13},
									{4, 14},
									{5, 15},
									{6, 16}};
	vector<int> result = s.spiralOrder(matrix);
	for (auto x:result) {
		cout<<x<<" ";
	}
}