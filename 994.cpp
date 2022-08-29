class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ret = -1;
        vector<pair<int, int>> v;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) v.push_back({i, j});
            }
        }
        if (v.empty()) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == 1) return -1;
                }
            }
            return 0;
        }

        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        while (!v.empty()) {
            ret++;
            vector<pair<int, int>> v2;
            for (auto &p: v) {
                for (int d = 0; d < 4; d++) {
                    int a = p.first + dx[d], b = p.second + dy[d];
                    if (0 <= min(a, b) && a < row && b < col && grid[a][b] == 1) {
                        grid[a][b] = 2;
                        v2.push_back({a, b});
                    }
                }
            }
            v = v2;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return ret;
    }
};