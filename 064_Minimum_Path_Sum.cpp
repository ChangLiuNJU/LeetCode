#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	int m = grid.size();
    	int n = grid[0].size();
    	int result[m][n];
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (i == 0 && j == 0) {
    				result[i][j] = grid[i][j];
    			} else if (i == 0) {
    				result[i][j] = grid[i][j] + result[i][j-1];
    			} else if (j == 0) {
    				result[i][j] = grid[i][j] + result[i-1][j];
    			} else {
    				result[i][j] = grid[i][j] + min(result[i-1][j], result[i][j-1]);
    			}

    		}
    	}
    	return result[m-1][n-1];
    }
};
int main() {
	Solution s;
	vector<vector<int> > grid;
	vector<int> v; v.push_back(0);
	grid.push_back(v);
	cout<<s.minPathSum(grid);
}