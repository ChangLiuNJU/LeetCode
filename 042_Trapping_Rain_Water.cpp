#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
    	if (n < 3) return 0;
    	int l[n];
    	int r[n];
    	l[0] = 0;
    	for (int i = 1; i < n; i ++) {
    		l[i] = max(l[i - 1], A[i - 1]);
    	}
    	r[n-1] = 0;
    	for (int i = n - 2; i >= 0; i --) {
    		r[i] = max(r[i + 1], A[i + 1]);
    	}
    	int result = 0;
    	for (int i = 0; i < n; i++) {
    		int tmp = min(l[i], r[i]) - A[i];
    		if (tmp > 0) {
    			result += tmp;
    		}
    	}
    	return result;
    }
};
int main() {
	Solution s;
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<s.trap(A, 12);
}