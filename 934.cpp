class Solution {
private:
    vector<vector<int>> g;
    vector<pair<int, int>> start;
    void init() {
        int n = g.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    g[i][j] = 0;
                    dfs(i, j);
                    return;
                }
            }
        }
    }
    void dfs(int i, int j) {
        start.push_back({i, j});
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int a = dx[d] + i, b = dy[d] + j;
            if (0 <= min(a, b) && max(a, b) < g.size() && g[a][b] == 1) {
                g[a][b] = 0;
                dfs(a, b);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        g = grid;
        init();
        int result = 0;
        // bfs
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        while (!start.empty()) {
            vector<pair<int, int>> v;
            for (auto &[i, j]: start) {
                // cout << i << ' ' << j << '\n';
                for (int d = 0; d < 4; d++) {
                    int a = dx[d] + i, b = dy[d] + j;
                    if (0 <= min(a, b) && max(a, b) < g.size()) {
                        if (g[a][b] == 1) {
                            return result;
                        } else if (g[a][b] == 0) {
                            g[a][b] = -1;
                            v.push_back({a, b});
                        }
                    }
                }
            }
            start = v;
            result++;
        }
        return -1;
    }
};