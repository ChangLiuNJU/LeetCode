#include <iostream>
using namespace std;

class Solution {
public:
	int binarySearch(int A[], int n, int target, int s, int t) {
		int mid = (s + t) / 2;
		if (s > t) return -1;
		if (A[mid] == target) return mid;
		int result;
		result = binarySearch(A, n, target, s, mid - 1);
		if (result != -1) return result;
		result = binarySearch(A, n, target, mid + 1, t);
		if (result != -1) return result;
		return -1;
	}
    int search(int A[], int n, int target) {
    	return binarySearch(A, n, target, 0, n-1);
    }
};
int main() {
	Solution s;
	int A[] = {4,5,6,7,0,1,2};
	cout<<s.search(A, 7, 6)<<endl;
}