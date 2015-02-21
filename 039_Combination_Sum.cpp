#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	vector<vector<int> > result;
    	if (candidates.size() <= 0 || candidates[0] > target) {
    		return result;
    	}
    	for (int i = 0; i < candidates.size(); i++) {
   			if (candidates[i] == target) {
   				result.push_back(vector<int>(1, target));
   				break;
   			}
   			vector<int> tmpCan(candidates.begin() + i, candidates.end());		
    		vector<vector<int> > tmp = combinationSum(tmpCan, target - candidates[i]);
    		for (int j = 0; j < tmp.size(); j++) {
    			vector<int> tmpJ = tmp[j];
    			tmpJ.insert(tmpJ.begin(), candidates[i]);
    			result.push_back(tmpJ);
    		}
    	}
    	return result;
    }
};
int main() {
	Solution s;
	vector<int> candidates({8, 7, 4, 3});
	vector<vector<int> > v = s.combinationSum(candidates, 11);
	for (auto i : v) {
		for (auto j : i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}