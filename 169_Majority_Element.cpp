#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
    	sort(num.begin(), num.end());
    	return num[num.size() / 2];
    }
};
int main() {
	Solution s;
	int a[] = {1,1,1,1,1,1,1,4,2,3,4,5};
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	cout<<s.majorityElement(v)<<endl;
	return 0;
}