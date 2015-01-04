#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> v;

        return v;
    }
};
int main() {
	Solution s;
	string start = "hit";
	string end   = "cog";
	unordered_set<string> dict ({"hot", "dot", "dog", "lot", "log"});
	vector<vector<string>> v = s.findLadders(start, end, dict);
	for (vector<vector<string>>::iterator i = v.begin(); i != v.end(); i++) {
		for (vector<string>::iterator j = i->begin(); j != i->end(); j++) {
			cout<<*j;
		}
		cout<<endl;
	}
}