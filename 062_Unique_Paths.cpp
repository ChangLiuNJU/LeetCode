#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
   		int result[m][n];
   		for (int i = 0; i < m; i++) {
   			for (int j = 0; j < n; j++) {
   				if (i == 0 || j == 0) {
   					result[i][j] = 1;
   				} else {
   					result[i][j] = result[i-1][j] + result[i][j-1];
   				}
   			}
   		}
   		return result[m-1][n-1];
   	}
};
int main() {
	Solution s;
	cout<<s.uniquePaths(99, 99);
	return 0;
}