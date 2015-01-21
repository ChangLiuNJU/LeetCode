#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
    	int s = 0;
    	int t = height.size()-1;
    	int max = 0;
    	while (s < t) {
    		if (height[s] < height[t]) {
    			if (max < height[s] * (t-s)) {
    				max = height[s] * (t-s);
    			}
    			s++;
    		} else {
    			if (max < height[t] * (t-s)) {
    				max = height[t] * (t-s);
    			}
    			t--;
    		}
    	}
    	return max;
    }
};
int main() {
	Solution s;
	int A[] = {2,3,4,1,5};
	vector<int> v(A, A+5);
	cout<<s.maxArea(v)<<endl;
}