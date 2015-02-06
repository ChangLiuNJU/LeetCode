#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	vector<int> result = digits;
    	int i = result.size() - 1;
    	int add = 1;
    	while (i >= 0 && add != 0) {
    		if (result[i] < 9) {
    			result[i] = result[i] + add;
    			add = 0;
    		}
    		else {
    			result[i] = 0;
    			add = 1;
    		}
    		i--;
    	}
    	if (add == 1) {
    		result.insert(result.begin(), 1);
    	} 
    	return result;
    }
};
int main() {
	Solution s;
	vector<int> v = {9};
	for (auto x:s.plusOne(v)) {
		cout<<x;
	}
}