class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> ret(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int a = i;
                int b = j + k;
                a += b / col;
                b %= col;
                a %= row;
                ret[a][b] = grid[i][j];
            }
        }
        return ret;
    }
};