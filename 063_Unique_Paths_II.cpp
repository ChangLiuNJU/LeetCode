#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
         return 0;
      }
      int result[m][n];
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
               result[i][j] = 0;
            } else {
               if (i == 0 && j == 0) {
                  result[i][j] = 1;
               } else if (i == 0) {
                  result[i][j] = result[i][j-1];
               } else if (j == 0) {
                  result[i][j] = result[i-1][j];
               } else {
                  result[i][j] = result[i-1][j] + result[i][j-1];
               }
            }
         }
      }
      return result[m-1][n-1];
   }
};
int main() {
	Solution s;
	vector<vector<int> > obstacleGrid({ {0, 0},
                                       {1, 1},
                                       {0, 0}});
   cout<<s.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}