class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        g = grid;
        row = g.size(), col = g[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (g[i][j] == 1) return dfs(i, j);
            }
        }
        return 0;
    }
private:
    vector<vector<int>> g;
    int row, col;
    int dfs(int i, int j) {
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

        g[i][j] = 2;
        int result = 0;
        for (int d = 0; d < 4; d++) {
            int u = i + dx[d], v = j + dy[d];
            if (0 <= min(u, v) && u < row && v < col) {
                if (g[u][v] == 1)
                    result += dfs(u, v);
                else if (g[u][v] == 0) {
                    result++;
                }
            } else {
                result++;
            }
        }
        return result;
    }
};