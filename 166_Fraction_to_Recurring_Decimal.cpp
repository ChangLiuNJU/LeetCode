#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	string s = "";
    	long long n = numerator;
    	long long d = denominator;
    	if ((n < 0) ^ (d < 0)) {
    		s = "-";
    	}
    	n = abs(n);
    	d = abs(d);

    	while (n >= d) {
    		s += to_string(n / d);
    		n = n % d;
    	}
    	if (n != 0) {
    		if (s == "" || s == "-") {
    			s += "0";
    		}
    		s += ".";
    		int index = s.size();
    		map<long long, int> table;
    		while (n * 10 < d) {
    			n *= 10;
    			s += "0";
    			table[n] = index;
    			index++;
    		}
    		while (n != 0) {
    			n *= 10;
    			if (table.count(n) > 0) {
    				s += ")";
					s.insert(table[n],1,'(');
    				break;
    			}
    			table[n] = index;
    			index++;
    			s += to_string(n / d);
    			n = n % d;
    		}
    	} else if (s == "" || s == "-") {
    		s = "0";
    	}
    	return s;
    }
};
int main() {
	Solution s;
	cout<<s.fractionToDecimal(-1, -2147483648)<<endl;
	cout<<s.fractionToDecimal(7, -12)<<endl;
	cout<<s.fractionToDecimal(0, -5)<<endl;
	cout<<s.fractionToDecimal(1, 5)<<endl;
	cout<<s.fractionToDecimal(0, 2)<<endl;
	cout<<s.fractionToDecimal(1, 2)<<endl;
	cout<<s.fractionToDecimal(2, 1)<<endl;
	cout<<s.fractionToDecimal(2, 3)<<endl;
	cout<<s.fractionToDecimal(1234, 9999)<<endl;

	return 0;
}