#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	int s = searchBegin(A, n, target, 0, n - 1);
    	int t = searchEnd(A, n, target, 0, n -1);
    	return vector<int>({s,t});   
    }
private:
	int searchBegin(int A[], int n, int target, int s, int t) {
		if (s > t) return -1;
		if (s == t) return A[s] == target ? s : -1;
		int mid = (s + t) / 2;
		
		if (A[mid] == target) {
			if (mid == 0) return 0;
			else if (A[mid - 1] == target) return searchBegin(A, n, target, s, mid - 1);
			else return mid;
		} else if (A[mid] < target) {
			return searchBegin(A, n, target, mid + 1, t);
		} else {
			return searchBegin(A, n, target, s, mid - 1);
		}
	}
	int searchEnd(int A[], int n, int target, int s, int t) {
		if (s > t) return -1;
		if (s == t) return A[s] == target ? s : -1;
		int mid = (s + t) / 2;

		if (A[mid] == target) {
			if (mid == n - 1) return n - 1;
			else if (A[mid + 1] == target) return searchEnd(A, n, target, mid + 1, t);
			else return mid;
		} else if (A[mid] < target) {
			return searchEnd(A, n, target, mid + 1, t);
		} else {
			return searchEnd(A, n, target, s, mid - 1);
		}
	}
};
int main() {
	Solution s;
	int A[] = {5, 7, 7, 8, 8, 10};
	vector<int> v = s.searchRange(A, sizeof(A) / 4, 8);
	cout<<v[0]<<" "<<v[1]<<endl;
}