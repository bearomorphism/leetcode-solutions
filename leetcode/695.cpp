class Solution {
private:
    int dfs(vector<vector<int>>& g, int x, int y) {
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int ret = 1;
        for (int d = 0; d < 4; d++) {
            int r = x + dx[d], c = y + dy[d];
            if (0 <= r && r < g.size() && 0 <= c && c < g[0].size() && g[r][c] == 1) {
                g[r][c] = 0;
                ret += dfs(g, r, c);
            }
        }
        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    ret = max(ret, dfs(grid, i, j));
                }
            }
        }
        return ret;
    }
};