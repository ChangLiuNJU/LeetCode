#include <iostream>
using namespace std;

class Solution {
public:
	int binarySearch(int A[], int n, int target, int s, int t) {
		int m = (s+t)/2;
		if (s == t) {
			if (s == 0 && target <= A[s])
				return 0;
			if (t == n-1 && target > A[t]) 
				return n;
			if (target > A[s-1] && target <= A[s])
				return s;
			return -1;
		}
		int r = binarySearch(A, n, target, s, m);
		if (r != -1) {
			return r;
		} else {
			r = binarySearch(A, n, target, m + 1, t);
		}
		return r;
	}
    int searchInsert(int A[], int n, int target) {
    	if (n == 0) return 0;
    	return binarySearch(A, n, target, 0, n-1);
    }
};
int main() {
	Solution s;
	int a[] = {1, 3, 5, 6};
	cout<<s.searchInsert(a, 4, 5)<<endl;
	cout<<s.searchInsert(a, 4, 2)<<endl;
	cout<<s.searchInsert(a, 4, 7)<<endl;
	cout<<s.searchInsert(a, 4, 0)<<endl;
	return 0;
}