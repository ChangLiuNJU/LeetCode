#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool isAdjacent(string x, string y) {
		int count = 0;
		for (int i = 0; i < x.size(); i++) {
			if (x[i] != y[i]) {
				count++;
			}
		}
		return count == 1; 
	}
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> result;
        dict.insert(start); dict.insert(end);

    	unordered_set<string> s; s.insert(start);
    	unordered_set<string> u = dict; u.erase(start); u.insert(end);
    	map<string, unordered_set<string>> father;

    	bool flag = true;	
    	while (flag) {
    		flag = false;
    		unordered_set<string> eraseFromU;

	    	for (unordered_set<string>::iterator i = s.begin(); i != s.end(); i++) {
	    		for (int j = 0; j < (*i).size(); j++) {
	    			for (char c = 'a'; c<='z'; c++) {
	    				if (c != (*i)[j]) {
	    					string tmp = *i;
	    					tmp[j] = c;
	    					if (u.find(tmp) != u.end()) {
	    						father[tmp].insert(*i);
	    						eraseFromU.insert(tmp);
	    					}
	    				}
	    			}
	    		}
	    	}

	    	s.clear();
	    	for (unordered_set<string>::iterator i = eraseFromU.begin(); i != eraseFromU.end(); i++) {
	    		s.insert(*i);
	    		u.erase(*i);
	    	}
	    	flag = eraseFromU.size() > 0;
	    }
	    flag = true;
	    vector<string> tmp; tmp.push_back(end);
	    result.push_back(tmp);
	    while (flag) {
	    	flag = false;
	    	for (vector<vector<string>>::iterator i = result.begin(); i != result.end(); i++) {
	    		string cur = (*i)[(*i).size()-1];
	    		if (cur != start) {
	    			vector<string> tmp = *i;
	    			result.erase(i);
	    			for (unordered_set<string>::iterator j = father[cur].begin(); j != father[cur].end(); j++) {
	    				vector<string> tmptmp = tmp;
	    				tmptmp.push_back(*j);
	    				result.push_back(tmptmp);
	    			}
	    			flag = true;
	    			break;
	    		}
	    	}
	    }
		for (vector<vector<string>>::iterator i = result.begin(); i != result.end(); i++) {
			reverse((*i).begin(), (*i).end());
		}
        return result;
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
			cout<<*j<<" ";
		}
		cout<<endl;
	}
}