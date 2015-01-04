#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
	int notNumberIndex(const char *s) {
		int i = 0;
		bool haveDot = false;
		bool beforeDot = false;
		bool afterDot = false;
		if (s[i] == '+' || s[i] == '-') {
			i++;
			if (s[i] == '\0' || s[i] == 'e') return -1;
		}
		while (isdigit(s[i])) {
			i++;
			beforeDot = true;
		}
		if (i == 0 && s[i] != '.') return -1;
		if (s[i] == '.') {
			i++;
			haveDot = true;
		}
		while (isdigit(s[i])) {
			i++;
			afterDot = true;
		}
		if (haveDot && (!beforeDot) && (!afterDot)) return -1;
		return i;
	}
    bool isNumber(const char *s) {
    	int i = 0;
    	while (s[i] == ' ') i++;
    	if (s[i] == '\0') return false;

    	int tmp = notNumberIndex(&s[i]);
    	if (tmp <= 0) return false;
    	i = i + tmp;
    	while (s[i] == ' ') {
			i++;
		};
		if (s[i] == '\0') return true;
		if (i > 0 && s[i-1] == ' ') return false;
    	if (s[i] != 'e') return false;
    	i++;
    	bool haveD = false;
    	if (s[i] == '+' || s[i] == '-') i++;
    	while (isdigit(s[i])) {
    		i++;
    		haveD = true;
    	}
    	if (!haveD) return false;
		while (s[i] == ' ') {
			i++;
		}
		if (s[i] != '\0') return false;
    	return true;
    }
};

int main() {
	Solution s;
	cout<<s.isNumber("1 ");
	cout<<s.isNumber(".");
	cout<<s.isNumber("0");
	cout<<s.isNumber(" 0.1 ");
	cout<<s.isNumber("abc");
	cout<<s.isNumber("1 a");
	cout<<s.isNumber("2e0");
	return 0;
}