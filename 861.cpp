class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < col; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        int ret = row * (1 << (col - 1));
        for (int j = 1; j < col; j++) {
            int cnt = 0;
            for (int k = 0; k < row; k++) {
                cnt += grid[k][j];
            }
            ret += max(cnt, row - cnt) * (1 << (col - 1 - j));
        }
        return ret;
    }
};