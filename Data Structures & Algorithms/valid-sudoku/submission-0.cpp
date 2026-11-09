using namespace std;

class Solution {
public:
    int toNum(char c) {
        if (c == '.')
            return 0;
        else
            return (c - '0');
    }
    int boxNum(int column) {
        if (column <= 2) {
            return 0;
        }
        else if (column <= 5) {
            return 1;
        }
        else {
            return 2;
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> rowTracker;
        vector<unordered_map<int, int>> boxTracker(3);
        vector<unordered_map<int, int>> columnTracker(9);
        for (int i{ 0 }; i < 9; ++i) {
            for (int j{ 0 }; j < 9; ++j) {
                int currentNumber = toNum(board[i][j]);
                int currentBox{ boxNum(j) };
                int rowCondition{ 0 }, boxCondition{ 0 }, columnCondition{ 0 };
                if (currentNumber != 0) {
                    rowCondition = ++rowTracker[currentNumber];
                    boxCondition = ++boxTracker[currentBox][currentNumber];
                    columnCondition = ++columnTracker[j][currentNumber];
                }
                if (rowCondition > 1 || boxCondition > 1 || columnCondition > 1)
                    return false;
            }
            rowTracker.clear();
            if (i == 2 || i == 5) {
                boxTracker[0].clear();
                boxTracker[1].clear();
                boxTracker[2].clear();
            }
        }
        return true;
    }
};