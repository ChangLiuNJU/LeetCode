#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	int k = 0;
    	int duplicates = 0;
    	for (int i = 0; i < n; i++) {
    		A[k] = A[i];
    		if (k != 0) {
    			if (A[k] == A[k-1]) {
    				duplicates++;
    			} else {
    				duplicates = 0;
    			}
    		}
    		if (duplicates < 2) {
    			k++;
    		}
    	}
    	return k;
    }
};

int main() {
	Solution s;
	int A[] = {1};
	cout<<s.removeDuplicates(A, 1)<<endl;
	for (int i = 0; i < 1; i++) 
		cout<<A[i];
}