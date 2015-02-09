#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	if (m == 0) {
    		for (int i = 0; i < n; i++) {
    			A[i] = B[i];
    		}
    		return;
    	}
    	if (n == 0) {
    		return;
    	}
    	int tmp[m];
    	memcpy(tmp, A, sizeof(tmp));
    	int i = 0;
    	int ai = 0;
    	int bi = 0;
    	while (i < m + n) {
    		if (ai < m && (bi > n - 1 || tmp[ai] <= B[bi])) {
    			A[i] = tmp[ai];
    			ai++;
    			i++;
    			continue;
    		}
    		if (bi < n && (ai > m - 1 || tmp[ai] > B[bi])) {
    			A[i] = B[bi];
    			bi++;
    			i++;
    			continue;
    		}
    	}
    }
};

int main() {
	Solution s;
	int A[63] = {};
	int B[63] = {-50,-50,-48,-47,-44,-44,-37,-35,-35,-32,-32,-31,-29,-29,-28,-26,-24,-23,-23,-21,-20,-19,-17,-15,-14,-12,-12,-11,-10,-9,-8,-5,-2,-2,1,1,3,4,4,7,7,7,9,10,11,12,14,16,17,18,21,21,24,31,33,34,35,36,41,41,46,48,48};
	s.merge(A, 0, B, 63);
	for (int i = 0; i < 63; i++) 
		cout<<A[i];
}