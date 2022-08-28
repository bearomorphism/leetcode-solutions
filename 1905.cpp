class Solution {
private:
    void dfs(vector<vector<int>> &g, int x, int y, vector<pair<int, int>>& ret) {
        int row = g.size(), col = g[0].size();
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int r = x + dx[d], c = y + dy[d];
            if (0 <= r && r < row && 0 <= c && c < col && g[r][c]) {
                g[r][c] = 0;
                ret.push_back({r, c});
                dfs(g, r, c, ret);
            }
        }
    }
    bool check(vector<vector<int>>& grid1, vector<pair<int, int>>& v) {
        for (auto &p: v) {
            if (!grid1[p.first][p.second]) return false;
        }
        return true;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ret = 0;
        int row = grid2.size(), col = grid2[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid2[i][j]) {
                    vector<pair<int, int>> v;
                    v.push_back({i, j});
                    grid2[i][j] = 0;
                    dfs(grid2, i, j, v);
                    if (check(grid1, v)) ret++;
                }
            }
        }
        return ret;
    }
};