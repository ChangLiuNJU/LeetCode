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
      vector<vector<string> > solveNQueens(int n) {
       	queue<vector<int>> q;
       	vector<vector<string> > result;
       	for (int i = 0; i < n; i++) {
       		vector<int> v;
       		v.push_back(i);
       		q.push(v);
       	}
       	while (!q.empty()) {
       		vector<int> v = q.front();
       		q.pop();
       		if (v.size() == n) {
       			vector<string> tmp;
                        string s(n, '.');
                        tmp.insert(tmp.end(), n, s);
                        for (int i = 0; i < n; i++) {
                              tmp[i][v[i]] = 'Q';
                        }
                        result.push_back(tmp);
       			continue;
       		}
       		for (int i = 0; i < n; i++) {
       			if (isValid(v, i)) {
       				vector<int> tmp = v;
       				tmp.push_back(i);
       				q.push(tmp);
       			}
       		}
       	}
       	return result;
    }
};

int main() {
	Solution s;
	vector<vector<string> > result = s.solveNQueens(8);
      for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                  cout<<result[i][j]<<endl;
            }
            cout<<endl;
      }
	return 0;
}
