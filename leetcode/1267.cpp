class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> rc(row, 0), cc(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    rc[i]++;
                    cc[j]++;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] && (rc[i] > 1 || cc[j] > 1)) ret++;
            }
        }
        return ret;
    }
};