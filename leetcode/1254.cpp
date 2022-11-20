class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            if (!grid[i][0]) dfs(i, 0, grid);
            if (!grid[i][col - 1]) dfs(i, col - 1, grid);
        }
        for (int i = 0; i < col; i++) {
            if (!grid[0][i]) dfs(0, i, grid);
            if (!grid[row - 1][i]) dfs(row - 1, i, grid);
        }

        int result = 0;
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (!grid[i][j]) {
                    result++;
                    dfs(i, j, grid);
                }
            }
        }
        return result;
    }
private:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        grid[i][j] = 1;
        int row = grid.size(), col = grid[0].size();
        for (int d = 0; d < 4; d++) {
            int a = i + dx[d], b = j + dy[d];
            if (0 <= min(a, b) && a < row && b < col && !grid[a][b]) {
                dfs(a, b, grid);
            }
        }
    }
};