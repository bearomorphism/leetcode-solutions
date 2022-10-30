class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int ret = 0;
        for (int i = 0; i < row; i++) {
            vector<int> mask(col, 1);
            for (int j = i; j < row; j++) {
                for (int c = 0; c < col; c++) {
                    if (matrix[j][c] == '0') mask[c] = 0;
                }
                int cnt = 0, cur = 0;
                for (int c = 0; c < col; c++) {
                    if (mask[c]) {
                        cnt++;
                        cur = max(cur, cnt);
                    } else {
                        cnt = 0;
                    }
                }
                ret = max(ret, (j - i + 1) * cur);
            }
        }
        return ret;
    }
};