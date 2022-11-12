class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<long long>> v1(m, vector<long long>(n));
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        while (maxMove--) {
            vector<vector<long long>> v2(m, vector<long long>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (0 <= min(x, y) && x < m && y < n)
                            v2[i][j] += v1[x][y];
                        else
                            v2[i][j]++;
                    }
                    v2[i][j] %= static_cast<int>(1e9 + 7);
                }
            }
            v1 = v2;
        }
        return v1[startRow][startColumn];
    }
};