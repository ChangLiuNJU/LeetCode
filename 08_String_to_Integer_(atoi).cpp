#include <iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
    	int result = 0;
    	int offset = 0;
    	int state  = 0;
    	int flag = 1;
 		while (*(str+offset) != '\0') {
 			char c = *(str+offset);
 			switch (state) {
 				case 0:
 					if (c == ' ') {
 					} else if (c == '+') {
 						state = 1;
 					} else if (c == '-') {
 						flag = -1;
 						state = 1;
 					} else if (c >= '0' && c <= '9') {
 						result = result * 10 + c - '0';
 						state = 2;
 					} else {
 						return 0;
 					}
 					break;
 				case 1:
 					if (c >= '0' && c <= '9') {
 						result = result * 10 + c - '0';
 						state = 2;
 					} else {
 						return 0;
 					}
 					break;
 				case 2:
 					if (c >= '0' && c <= '9') {
 						long long tmp = result;
 						tmp = (tmp * 10 + c - '0') * flag;
 						if (tmp > INT_MAX) return INT_MAX;
 						if (tmp < INT_MIN) return INT_MIN;
 						result = result * 10 + c - '0';
 					} else {
 						state = 3;
 					}
 					break;
 				case 3:
 					break;
 			}
 			offset ++;
 		}
 		
        return result * flag;
    }
};

int main() {
	Solution s;
	cout<<s.atoi("   -2147483612312366asdfasdfasdf   ")<<endl;
}
