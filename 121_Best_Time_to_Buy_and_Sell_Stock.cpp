#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int result = 0;
        int minPrice = 2147483647;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            result = max(result, prices[i] - minPrice);
        }
        return result;
    }
};
int main() {
	Solution s;
	int A[] = {3,1,6,4,5};
	vector<int> v(A, A + 5);
	cout<<s.maxProfit(v)<<endl;
	return 0;
}