#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int binarySearch(const vector<int> &num, int s, int t) {
		if (s > t) return -1;
		int mid = (s + t) / 2;
		if (mid == 0) {
			if (num[mid] > num[mid+1]) return mid;
		} else if (mid == num.size()-1) {
			if (num[mid] > num[mid-1]) return mid;
		} else if (num[mid] > num[mid+1] && num[mid] > num[mid-1]) {
			return mid;
		} else if (s == t) {
			return -1;
		}
		int result = -1;
		result = binarySearch(num, s, mid-1);
		if (result != -1) return result;
		result = binarySearch(num, mid+1, t);
		if (result != -1) return result;
		return -1;
	}
    int findPeakElement(const vector<int> &num) {
    	if (num.size() == 1) return 0;
    	return binarySearch(num, 0, num.size()-1);
    }
};
int main() {
	Solution s;
	int A[] = {1,2,3,1};
	vector<int> v(A, A+4);
	cout<<s.findPeakElement(v);
}