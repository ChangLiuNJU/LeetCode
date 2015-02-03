#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	int s = 0;
    	int t = matrix.size() * matrix[0].size() - 1;
    	while (s <= t) {
    		int mid = (s + t) / 2;
    		int midx = mid / matrix[0].size();
    		int midy = mid % matrix[0].size();
    		if (matrix[midx][midy] == target) return true;
    		if (matrix[midx][midy] < target) s = mid+1;
    		if (matrix[midx][midy] > target) t = mid-1;
    	}
    	return false;
    }
};
int main() {
	Solution s;
	int a[] = {1};
	vector<int> v1(a, a+1);
	// int b[] = {10,11,15,20};
	// vector<int> v2(b, b+4);
	// int c[] = {23,30,34,50};
	// vector<int> v3(c, c+4);
	vector<vector<int> > v;
	v.push_back(v1);
	// v.push_back(v2);
	// v.push_back(v3);
	cout<<s.searchMatrix(v, 0);
}