class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find row
        int bottom{ static_cast<int>(matrix.size()) };
        int top{ 0 };
        int cur{ 0 };
        while ((bottom - top) / 2 + top != cur) {
            cur = (bottom - top) / 2 + top;
            if (target >= matrix[cur][0] && target <= matrix[cur][matrix[cur].size() - 1])
                break;
            if (target >= matrix[cur][0]) {
                top = cur;
            }
            else {
                bottom = cur;
            }
        }
        //find num in col
        int r { static_cast<int>(matrix[cur].size()) };
        int l { 0 };
        int currenRow = cur;
        cur = 0;
        while ((r - l) / 2 + l != cur) {
            cur = (r - l) / 2 + l;
            if (target == matrix[currenRow][cur])
                return true;
            else if (target > matrix[currenRow][cur])
                l = cur;
            else
                r = cur;
        }

        return target == matrix[currenRow][cur];
    }
};