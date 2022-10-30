class Solution {
private:
    void dfs(vector<vector<int>> &heights, int r, int c, vector<vector<bool>> &vis) {
        int row = heights.size(), col = heights[0].size();
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        vis[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int a = r + dx[d], b = c + dy[d];
            if (0 <= min(a, b) && a < row && b < col && !vis[a][b] && heights[a][b] >= heights[r][c]) {
                dfs(heights, a, b, vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> vis1(row, vector<bool>(col, false)), vis2(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, vis1);
            dfs(heights, i, col - 1, vis2);
        }
        for (int j = 0; j < col; j++) {
            dfs(heights, 0, j, vis1);
            dfs(heights, row - 1, j, vis2);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
};