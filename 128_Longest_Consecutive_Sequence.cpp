#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
   		unordered_set<int> num_copy(num.begin(), num.end());
    	unordered_set<int> searched;
    	int result = 0;
    	for (int i : num) {
    		if (searched.find(i) != searched.end()) {
    			continue;
    		}
    		searched.insert(i);
    		int j = i - 1;
    		while (num_copy.find(j) != num_copy.end()) {
    			searched.insert(j--);
    		} 
    		int k = i + 1;
    		while (num_copy.find(k) != num_copy.end()) {
    			searched.insert(k++);
    		}
    		result = max(result, k - j - 1);
    	}
    	return result;
    }
};
int main() {
	Solution s;
	vector<int> v({100, 4, 200, 1, 3, 2});
	cout<<s.longestConsecutive(v);
}