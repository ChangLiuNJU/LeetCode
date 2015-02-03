#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string getStr(vector<string> buf, int curWords, int curLen, int L) {
		string result;
		if (buf.size() == 1) {
			result = buf[0];
			for (int i = 0; i < L-buf[0].length(); i++) result += " ";
			return result;
		}
		int spacesForEach = (L - curLen) / (curWords - 1);
		int r = (L - curLen) % (curWords - 1);
		for (int i = 0; i < buf.size() -1; i++) {
			result += buf[i];
			if (i < r) {
				string tmp(spacesForEach + 1, ' ');
				result += tmp;
			} else {
				string tmp(spacesForEach, ' ');
				result += tmp;
			}
		}
		result += buf[buf.size()-1];
		return result;
	}
	string lastLine(vector<string> buf, int L) {
		string result;
		for (int i = 0; i < buf.size() - 1; i++) {
			result += buf[i];
			result += " ";
		}
		result += buf[buf.size()-1];
		string tmp(L - result.length(), ' ');
		return result+tmp;
	}
    vector<string> fullJustify(vector<string> &words, int L) {
		int curLen = 0;
		int curWords = 0;
		vector<string> result;
		vector<string> buf;
		int i = 0;
		while (i < words.size()) {
			if (curLen + words[i].length() + curWords > L) {
				if (curWords > 0) {
					result.push_back(getStr(buf, curWords, curLen, L));
					buf.clear();
					curLen = curWords = 0;
				}
			} else {
				buf.push_back(words[i]);
				curLen += words[i].length();
				curWords++;
				i++;
			}
		}
		result.push_back(lastLine(buf, L));
		return result;  
    }
};
int main() {
	Solution s;
	string str[] = {""};
	vector<string> v(str, str+1);
	vector<string> result = s.fullJustify(v, 2);
	for (int i = 0; i < result.size(); i++) {
		cout<<result[i]<<'#'<<endl;
	}
}