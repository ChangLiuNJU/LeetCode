#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
    	int min = num[0];
    	for (int i = 1; i < num.size(); i++) {
    		if (num[i] < min) {
    			min = num[i];
    		}
    	}
    	return min;
    }
};
int main() {
	Solution s;
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> v(a, a + 7);
	cout<<s.findMin(v)<<endl;
	return 0;
}