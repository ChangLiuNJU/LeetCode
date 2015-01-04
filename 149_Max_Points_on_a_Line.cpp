#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
    	int max = 0;
        for (vector<Point>::iterator i = points.begin(); i != points.end(); i++) {
        	int vertical = 1;
        	int same = 0;
        	map<double, int> table;
        	for (vector<Point>::iterator j = points.begin(); j != points.end(); j++) {
        		if (i == j) continue;
        		if (j->x == i->x && j->y == i->y) {
        			same++;
        		}
        		else if (j->x - i->x == 0) {
        			vertical++;
        		} else {
        			table[(double)(j->y - i->y) / (double)(j->x - i->x)] ++;
        		}
        	}
        	if (vertical + same > max) max = vertical + same;
	    	for (map<double, int>::iterator iter = table.begin(); iter != table.end(); iter++) {
	    		if (iter->second + 1 + same > max) {
	    			max = iter->second + 1 + same;
	    		}
	    	}

        }
    	return max;
    }
};

int main() {
	vector<Point> points;
	points.push_back(*(new Point(1, 1)));
	points.push_back(*(new Point(1, 1)));
	points.push_back(*(new Point(2, 2)));
	points.push_back(*(new Point(2, 2)));

	Solution s;
	cout<<s.maxPoints(points)<<endl;
	return 0;
}