/*
	Record the Diff value and index, and use map to search quickly.
	Target 		int				9 
	Numbers 	vector<int>		2 	  7     11     15
	Diff        map<int, int>	<7,0> <2,1> <-2,2> <-6,3>         
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> result;
    	map<int, int> diff;
 		for (int i = 0; i < numbers.size(); i++) {
 			diff.insert(map<int,int>::value_type(target - numbers[i], i));
 		}
 		for (int i = 0; i < numbers.size(); i++) {
 			map<int, int>::iterator tmp;
 			tmp = diff.find(numbers[i]);
 			if ((tmp != diff.end()) && (i != diff[i])) {
 				int x = numbers[i];
 				for (int i = 0; i < numbers.size(); i++) {
 					if (numbers[i] == x || numbers[i] == target - x) {
 						result.push_back(i+1);
 						x = target - x;
 						if (result.size() == 2) {
 							return result;
 						}
 					}
 				}
 			}
 		}
    	return result;
    }
};
int main() {
	Solution s;
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	vector<int> result = s.twoSum(v, 6);
	cout<<result[0]<<" "<<result[1]<<endl;
	return 0;
}
