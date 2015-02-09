#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > com(int s, int t, int k) {
		vector<vector<int> > result;
		if (t - s + 1 < k || k == 0) return result;
		if (k == 1) {
			for (int i = s; i <= t; i++) {
				vector<int> tmp; 
				tmp.push_back(i);
				result.push_back(tmp);
			}
			return result;
		} else {
			result = com(s + 1, t, k);
			vector<vector<int> > p = com(s + 1, t, k - 1);
			for (int i = 0; i < p.size(); i++) {
				vector<int> tmp = p[i];
				tmp.insert(tmp.begin(), s);
				result.push_back(tmp);
			}
			return result;
		}
	}
    vector<vector<int> > combine(int n, int k) {
    	return com(1, n, k);
    }
};
int main() {
	Solution s;
	vector<vector<int> > v = s.combine(4, 4);
	for (auto i:v) {
		for (auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}