#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int j = 0;
        for (int i = 0; i < n; i++) {
        	if (A[i] != elem) {
        		A[j] = A[i];
        		j++;
        	}
        }
        return j;
    }
};

int main() {
	Solution s;
	int A[] = {2, 2, 5};
	cout<<s.removeElement(A, 3, 2);
	cout<<A[0];
}
