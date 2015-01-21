#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	bool isValid(vector<int> v, int x) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == x || v[i] == x - (v.size() - i) || v[i] == x + (v.size() - i)) {
				return false;
			}
		}
		return true;
	}
    int totalNQueens(int n) {
       	queue<vector<int>> q;
       	int result = 0;
       	for (int i = 0; i < n; i++) {
       		vector<int> v;
       		v.push_back(i);
       		q.push(v);
       	}
       	while (!q.empty()) {
       		vector<int> v = q.front();
       		q.pop();
       		if (v.size() == n) {
       			result++;
       			continue;
       		}
       		for (int i = 0; i < n; i++) {
       			if (isValid(v, i)) {
       				vector<int> tmp = v;
       				tmp.push_back(i);
       				;q.push(tmp);
       			}
       		}
       	}
       	return result;
    }
};

int main() {
	Solution s;
	cout<<s.totalNQueens(2)<<endl;
	return 0;
}
