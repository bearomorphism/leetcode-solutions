typedef pair<int, pair<int, int>> iPair;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        pq.push({0, {0, 0}});
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int ans = grid[0][0];
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int x = p.second.first, y = p.second.second;
            if (!vis[x][y]) {
                vis[x][y] = true;
                ans = max(ans, p.first);
                if (x == row - 1 && y == col - 1) return ans;
                for (int d = 0; d < 4; d++) {
                    int a = x + dx[d], b = y + dy[d];
                    if (0 <= min(a, b) && a < row && b < col && !vis[a][b]) {
                        pq.push({grid[a][b], {a, b}});
                    }
                }
            }
        }
        return -1;
    }
};