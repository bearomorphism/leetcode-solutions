class Solution {
    using P = pair<int, int>;
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> idx(row, vector<int>(col));

        int result = 0, k = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    vector<P> v;
                    dfs({i, j}, v, grid);
                    int n = v.size();
                    result = max(result, n);
                    for (auto &[x, y]: v) {
                        grid[x][y] = n;
                        idx[x][y] = k;
                    }
                    k++;
                }
            }
        }

        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    int merged = 1;
                    vector<int> vis;
                    for (int d = 0; d < 4; d++) {
                        int a = i + dx[d], b = j + dy[d];
                        if (0 <= min(a, b) && a < row && b < col && find(vis.begin(), vis.end(), idx[a][b]) == vis.end()) {
                            merged += grid[a][b];
                            vis.push_back(idx[a][b]);
                        }
                    }
                    result = max(result, merged);
                }
            }
        }
        return result;
    }
private:
    void dfs(P p, vector<P> &v, vector<vector<int>> &grid) {
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        auto &[x, y] = p;
        grid[x][y] = 0;
        v.push_back({x, y});
        for (int d = 0; d < 4; d++) {
            int a = x + dx[d], b = y + dy[d];
            if (0 <= min(a, b) && a < grid.size() && b < grid[0].size() && grid[a][b] == 1) {
                dfs({a, b}, v, grid);
            }
        }
    }
};