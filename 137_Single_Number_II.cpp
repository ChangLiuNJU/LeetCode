#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int count[32] = {0};
    	int result = 0;
    	for (int i = 0; i < 32; i++) {
    		for (int j = 0; j < n; j++) {
    			count[i] += (A[j]>>i) & 1;
    		}
    		result |= (count[i] % 3)<<i;
    	}
    	return result;
    }
};

int main() {
	Solution s;
	int A[] = {1, 1, 1, -2, 3, 3, 3};
	cout<<s.singleNumber(A, 7)<<endl;
	return 0;
}