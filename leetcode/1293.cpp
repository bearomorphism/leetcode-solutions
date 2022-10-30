class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        k++;
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

        int row = grid.size(), col = grid[0].size();
        if (row == 1 && col == 1) return 0;
        vector<vector<vector<bool>>> vis(row, vector<vector<bool>>(col, vector<bool>(k)));
        vector<tuple<int, int, int>> v, v2;
        v.push_back({0,0,0});
        vis[0][0][0] = true;

        int ret = 0;
        while (!v.empty()) {
            ret++;
            for (auto [x, y, h]: v) {
                for (int d = 0; d < 4; d++) {
                    int a = x + dx[d], b = y + dy[d];
                    if (a == row - 1 && b == col - 1) return ret;
                    if (0 <= min(a, b) && a < row && b < col) {
                        int g = h + grid[a][b];
                        if (g < k) {
                            if (!vis[a][b][g]) {
                                vis[a][b][g] = true;
                                v2.push_back({a, b, g});
                            }
                        }
                    }
                }
            }
            v = v2;
            v2.clear();
        }

        return -1;
    }
};