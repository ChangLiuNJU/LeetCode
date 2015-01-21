#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
	/*
		Binary to Gray
		For a n-bits binary, g(n) = b(n)
		for i < n g(i) = b(i) ^ b(i+1) 
	*/
	int btog(int b, int n) {
		int g = 0;
		for (int i = 0; i < n-1; i++) {
			g += b & ((int)pow(2, i)) ^ ((b & ((int)pow(2, i+1))) >> 1);
		}
		g += b & ((int)pow(2, n-1));
		return g;
	}
    vector<int> grayCode(int n) {
    	vector<int> v;
    	for (int i = 0; i < pow(2, n); i++) {
    		v.push_back(btog(i, n));
    	}
    	return v;  
    }
};

int main() {
	Solution s;
	vector<int> v = s.grayCode(2);
	for (int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}