class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<int> cntRow(row), cntCol(col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cntRow[i] += mat[i][j];
                cntCol[j] += mat[i][j];
            }
        }
        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1 && cntRow[i] == 1 && cntCol[j] == 1) result++;
            }
        }
        return result;
    }
};