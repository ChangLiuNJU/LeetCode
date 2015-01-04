#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int profit = 0;
    	for (int i = 1; i < prices.size(); i++) {
    		if (prices[i] > prices[i-1]) {
    			profit += prices[i] - prices[i-1];
    		}
    	}
        return profit;
    }
};
int main() {
	Solution s;
	int array[] = {27, 1, 3, 4, 2, 1, 6};
	vector<int> v(array, array + sizeof(array)/sizeof(int));
	cout<<s.maxProfit(v);
	return 0;
}