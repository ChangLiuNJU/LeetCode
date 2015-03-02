#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	bool isValid(vector<int> v) {
        int count[9] = {};
        for (int i = 0; i < v.size(); i++) {
            count[v[i] - 1]++;
            if (count[v[i] - 1] > 1) return false;
        }
        return true;
	}
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            vector<int> v;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    v.push_back(board[i][j] - '0');
                }
            }
            if (!isValid(v)) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            vector<int> v;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    v.push_back(board[i][j] - '0');
                }
            }
            if (!isValid(v)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<int> v;
            for (int j = 0; j < 9; j++) {
                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.') {
                    v.push_back(board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0');
                }  
            }
            if (!isValid(v)) return false;
        } 
        return true;
    }
};
int main() {
	Solution s;
	vector<vector<char> > board({{'5','3','.','.','7','.','.','.','.'},
								 {'6','.','.','1','9','5','.','.','.'},
								 {'.','9','8','.','.','.','.','6','.'},
								 {'8','.','.','.','6','.','.','.','3'},
								 {'4','.','.','8','.','3','.','.','1'},
								 {'7','.','.','.','2','.','.','.','6'},
								 {'.','6','.','.','.','.','2','8','.'},
								 {'.','.','.','4','1','9','.','.','5'},
								 {'.','.','.','.','8','.','.','7','9'},});
	cout<<s.isValidSudoku(board);
}