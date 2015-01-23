#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		int n = num.size();
		vector<vector<int> > result;
		if (n == 1) {
			result.push_back(num);
			return result;
		}
		for (int i = 0; i < n; i++) {
			vector<int> cur = num;
			cur.erase(cur.begin()+i);
			vector<vector<int> > v = permute(cur);
			for (int j = 0; j < v.size(); j++) {
				vector<int> tmp = v[j];
				tmp.insert(tmp.begin(), num[i]);
				result.push_back(tmp);
			}
		}
		return result;	        
    }
};
int main() {
	vector<int> v;
	v.push_back(1);v.push_back(2);v.push_back(3);
	Solution s;
	vector<vector<int> > result = s.permute(v);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}