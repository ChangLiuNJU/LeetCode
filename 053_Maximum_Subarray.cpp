#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int f[n];
    	int result[n];
    	for (int i = 0; i < n; i++) {
    		f[i] = A[i];
    		if (i == 0) {
    			continue;
    		} else if (f[i-1] + A[i] > f[i]) {
    			f[i] = f[i-1] + A[i];
    		}
    	}
    	for (int i = 0; i < n; i++) {
    		result[i] = A[i];
    		if (i == 0) {
    			continue;
    		}
    		if (result[i-1] > result[i]) {
    			result[i] = result[i-1];
    		}
    		if (f[i] > result[i]) {
    			result[i] = f[i];
    		}
    	}
    	return result[n-1];
    }
};

int main() {
	Solution s;
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout<<s.maxSubArray(A, 9);
	return 0;
}