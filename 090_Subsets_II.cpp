#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
    	vector<vector<int> > ret;
    	if (S.size() == 1) {
    		vector<int> null;
    		vector<int> v(1, S[0]);
    		ret.push_back(null); ret.push_back(v);
    	} else if (S.size() > 1) {
    		sort(S.begin(), S.end());
    		vector<int> tmpS(S.begin() + 1, S.end());
    		vector<vector<int> > tmp = subsetsWithDup(tmpS);
    		for (int i = 0; i < tmp.size(); i++) {
    			vector<int> t1 = tmp[i];
    			vector<int> t2(t1);
    			t2.insert(t2.begin(), S[0]);
    			if (find(ret.begin(), ret.end(), t1) == ret.end()) ret.push_back(t1);
    			if (find(ret.begin(), ret.end(), t2) == ret.end()) ret.push_back(t2);
    		}
    	}
    	return ret;
    }
};
int main() {
	Solution s;
	vector<int> v({4,1,0});
	vector<vector<int> > result = s.subsetsWithDup(v);
	for (auto i:result) {
		for (auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}