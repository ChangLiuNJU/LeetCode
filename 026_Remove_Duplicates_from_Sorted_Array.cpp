#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if (n == 1) return n;
    	int i = 1;
    	int duplicates = 0;
    	int x = A[0];
    	for (int k = 1; k < n; k++) {
    		if (A[k] == x) {
    			duplicates++;	
    		} else {
    			x = A[k];
    			A[i] = x;
    			i++;
    		}
    	}
    	return n - duplicates;  
    }
};
int main() {
	Solution s;
	int A[] = {1};
	cout<<s.removeDuplicates(A, 1)<<endl;
	for (int i = 0; i < 1; i++) 
		cout<<A[i];
}