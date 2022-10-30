class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int u = grid[p.first][p.second];
            for (int i = 0; i < 4; i++) {
                int x = p.first + dx[i], y = p.second + dy[i];
                if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] == 0) {
                    grid[x][y] = u + 1;
                    q.push({x, y});
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ret = max(ret, grid[i][j]);
            }
        }
        return ret > 1 ? ret - 1 : -1;
    }
};