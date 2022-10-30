class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size(), col = maze[0].size();
        vector<pair<int, int>> v;
        int ans = 0;
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        v.push_back({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while (v.size()) {
            vector<pair<int, int>> v2;
            ans++;
            for (auto &p: v) {
                for (int d = 0; d < 4; d++) {
                    int a = p.first + dx[d], b = p.second + dy[d];
                    if (0 <= min(a, b) && a < row && b < col && maze[a][b] == '.') {
                        if (a == 0 || a == row - 1 || b == 0 || b == col - 1) {
                            return ans;
                        }
                        maze[a][b] = '+';
                        v2.push_back({a, b});
                    }
                }
            }
            v = v2;
        }
        return -1;
    }
};