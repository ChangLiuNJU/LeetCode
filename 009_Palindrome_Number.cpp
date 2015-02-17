#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    	if (x == 0) return true;
    	if (x < 0 || x % 10 == 0) {
    		return false;
    	}
    	int y;
    	for (y = 0; y < x; x /= 10) {
    		y = y * 10 + x % 10;
    	}
    	return (x == y || y / 10 == x ? true : false);
    }
};
int main() {
	Solution s;
	cout<<s.isPalindrome(0)<<endl;
}