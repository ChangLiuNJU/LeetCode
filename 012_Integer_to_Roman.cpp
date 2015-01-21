#include <iostream>
using namespace std;

class Solution {
public:
	string s[4][3] = {{"I", "V", "X"},
					  {"X", "L", "C"},
					  {"C", "D", "M"},
					  {"M", "", ""}};
    string intToRoman(int num) {
        string result;
        int k = 0;
        while (num > 0) {
        	int x = num % 10;
        	switch (x) {
        		case 0:
        			break;
        		case 1:
        			result = s[k][0] + result;
        			break;
        		case 2:
        			result = s[k][0] + s[k][0] + result;
        			break;
        		case 3:
        			result = s[k][0] + s[k][0] + s[k][0] + result;
        			break;
        		case 4:
        			result = s[k][0] + s[k][1] + result;
        			break;
        		case 5:
        			result = s[k][1] + result;
        			break;
        		case 6:
        			result = s[k][1] + s[k][0] + result;
        			break;
        		case 7:
        			result = s[k][1] + s[k][0] + s[k][0] + result;
        			break;
        		case 8:
        			result = s[k][1] + s[k][0] + s[k][0] + s[k][0] + result;
        			break;
        		case 9:
        			result = s[k][0] + s[k][2] + result;
        			break;
        	}

        	num = num / 10;
        	k++;
        }
        return result;
    }
};

int main() {
	Solution s;
	cout<<s.intToRoman(1899)<<endl;
	return 0;
}