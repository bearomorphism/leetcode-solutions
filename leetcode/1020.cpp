class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            dfs(i, 0, grid);
            dfs(i, col - 1, grid);
        }
        for (int i = 0; i < col; i++) {
            dfs(0, i, grid);
            dfs(row - 1, i, grid);
        }

        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    result++;
                }
            }
        }
        return result;
    }
private:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        if (!grid[i][j]) return;
        grid[i][j] = 0;
        for (int d = 0; d < 4; d++) {
            int a = i + dx[d], b = j + dy[d];
            if (0 <= min(a, b) && a < grid.size() && b < grid[0].size() && grid[a][b]) {
                dfs(a, b, grid);
            }
        }
    }
};