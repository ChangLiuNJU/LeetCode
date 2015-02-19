#include <iostream>
using namespace std;
/*
	All zero comes from 5 * 2
	As 2 awlays ample, we count how many 5 factor in n!
	and some factor have more than one factor 5,
	so we trailingZeroes(n / 5) to take them.
*/
class Solution {
public:
    int trailingZeroes(int n) {
    	return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);  
    }
};
int main() {
	Solution s;
	cout<<s.trailingZeroes(10);
}