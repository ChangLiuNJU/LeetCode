#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	const char *p = s;
    	int result = 0;
    	while (*p != '\0') {
    		if (*(p - 1)  == ' ' && *p != ' ') {
    			result = 1;
    		} else if (*p != ' ') {
    			result++;
    		}
    		p++;
    	}
    	return result;
    }
};
int main() {
	Solution s;
	cout<<s.lengthOfLastWord("aaa aa  ");
}