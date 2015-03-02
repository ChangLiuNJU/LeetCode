#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
    	bool can[n];
    	for (int i = 0; i < n; i++) can[i] = false;
    	can[n - 1] = true;
    	for (int i = n - 2; i >= 0; i--) {
    		bool c = false;
    		int k = i + 1;
    		while (k < n && k <= i + A[i]) {
    			c = can[k];
    			if (c) break;
    			k = k + A[k] + 1;
    		}
    		can[i] = c;
    	}
    	return can[0];
    }
};
int main() {
	Solution s;
	int A[] = {3,2,1,0,4};
	cout<<s.canJump(A, 5);
}