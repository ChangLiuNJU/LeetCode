#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
    	int count[] = {0, 0, 0};
    	for (int i = 0; i < n; i++) {
    		count[A[i]]++;
    	}
    	for (int i = 0; i < n; i++) {
    		if (i < count[0]) A[i] = 0;
    		else if (i < count[0] + count[1]) A[i] = 1;
    		else A[i] = 2;
    	}
    }
};
int main() {
	Solution s;
	int A[] = {1,1,1,2,1,1,0,0};
	s.sortColors(A, 8);
	for (int i = 0; i < 8; i++) {
		cout<<A[i];
	}
	return 0;
}